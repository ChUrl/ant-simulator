#include "ant.hpp"

std::tuple<int, int> direction_to_offset(direction dir) {
    switch (dir) {
    case direction::NORTH:
        return std::make_tuple<int, int>(0, 1);
    case direction::EAST:
        return std::make_tuple<int, int>(1, 0);
    case direction::SOUTH:
        return std::make_tuple<int, int>(0, -1);
    case direction::WEST:
        return std::make_tuple<int, int>(-1, 0);
    }
}

// TODO: Should every ant have its own random generators? Why not initialize with coordinates and put the random numbers in there (from main)
Ant::Ant(PheromoneMap& pheromones)
  : WorldObject(0, 0, 3, sf::Color::Black), pheromones(pheromones) {
    std::random_device rd;   // obtain a random number from hardware
    std::mt19937 gen(rd());  // seed the generator

    std::uniform_int_distribution<> width_distribution(0, WIDTH);
    x = width_distribution(gen);

    std::uniform_int_distribution<> height_distribution(0, HEIGHT);
    y = height_distribution(gen);

    std::uniform_int_distribution<> dir_distribution(0, 3);
    dir = (direction)dir_distribution(gen);

    updateAppearance();
}

void Ant::addToUmwelt(const std::shared_ptr<WorldObject>& object) {
    umwelt.push_back(object);
}

void Ant::update() {
    move();

    // Respect borders
    if (isOffScreen()) {
        dir = (direction)((dir + 2) % 4);

        x += std::get<0>(direction_to_offset(dir)) * speed;
        y += std::get<1>(direction_to_offset(dir)) * speed;

        return;
    }

    updateAppearance();
    if (has_food) {
        dropPheromone();
    }
}

void Ant::move() {
    for (const auto& world_obj : umwelt) {
        if (world_obj->has_pheromones() && collides(*world_obj)) {
            has_food = true;
        } else if (collides(*world_obj)) {
            has_food = false;
        }
    }

    // TODO: Should this random generator be created on every move or should the ant carry it always?
    std::random_device device;   // obtain a random number from hardware
    std::mt19937 gen(device());  // seed the generator

    if (has_food) {
        move_to_base();
    } else {
        // Change direction randomly
        std::uniform_int_distribution<> dir_distribution(-1, 1);
        if (dir_distribution(gen) == 0) {
            // Change direction less often (1/3 of the time)
            dir = (direction)(((unsigned int)dir + (dir_distribution(gen) + 4)) % 4);  // + 4 so the value won't become negative
        }
    }

    // Move
    x += std::get<0>(direction_to_offset(dir)) * speed;
    y += std::get<1>(direction_to_offset(dir)) * speed;
}

// TODO: Replace umwelt with direct references to base/food and update this
void Ant::move_to_base() {
    if (x < WIDTH / 2) {
        dir = direction::EAST;
    } else if (y < HEIGHT / 2) {
        dir = direction::NORTH;
    } else if (x > WIDTH / 2) {
        dir = direction::WEST;
    } else if (y > HEIGHT / 2) {
        dir = direction::SOUTH;
    }
}

void Ant::updateAppearance() {
    appearance.setPosition(x, y);
}

void Ant::dropPheromone() {
    if (isOffScreen()) {
        std::cout << "Ant can't drop PheromoneMap offscreen!" << std::endl;
        return;
    }

    pheromones.place(x, y);
}
