#include "ant.hpp"

// TODO: Should every ant have its own random generators? Why not initialize with coordinates and put the random numbers in there (from main)
Ant::Ant(PheromoneMap& pheromones, double x, double y)
  : WorldObject(x, y, 3, sf::Color::Black), pheromones(pheromones) {
    std::random_device rd;   // obtain a random number from hardware
    std::mt19937 gen(rd());  // seed the generator

    std::uniform_real_distribution<> degree_distribution(0, 2 * std::numbers::pi);
    direction = degree_distribution(gen);
}

Ant::Ant(PheromoneMap& pheromones, unsigned int direction)
  : WorldObject(0, 0, 3, sf::Color::Black), direction(direction),
    pheromones(pheromones) {
    std::random_device device;         // obtain a random number from hardware
    std::mt19937 generator(device());  // seed the generator

    std::uniform_int_distribution<> width_distribution(0, WIDTH);
    x = width_distribution(generator);

    std::uniform_int_distribution<> height_distribution(0, HEIGHT);
    y = height_distribution(generator);

    updateAppearance();
}

Ant::Ant(PheromoneMap& pheromones)
  : WorldObject(0, 0, 3, sf::Color::Black), pheromones(pheromones) {
    std::random_device device;         // obtain a random number from hardware
    std::mt19937 generator(device());  // seed the generator

    std::uniform_int_distribution<> width_distribution(0, WIDTH);
    x = width_distribution(generator);

    std::uniform_int_distribution<> height_distribution(0, HEIGHT);
    y = height_distribution(generator);

    std::uniform_real_distribution<> degree_distribution(0, 2 * std::numbers::pi);
    direction = degree_distribution(generator);

    updateAppearance();
}

void Ant::addToUmwelt(const std::shared_ptr<WorldObject>& object) {
    umwelt.push_back(object);
}

void Ant::update() {
    move();

    // Respect borders
    if (isOffScreen()) {
        direction += std::numbers::pi / 2;

        x += std::cos(direction) * speed;
        y += std::sin(direction) * speed;

        return;
    }

    updateAppearance();
}

void Ant::move() {
    // TODO: Should this random generator be created on every move?
    std::random_device device;         // obtain a random number from hardware
    std::mt19937 generator(device());  // seed the generator

    // Move
    std::uniform_real_distribution<> degree_distribution(-std::numbers::pi, std::numbers::pi);

    direction += degree_distribution(generator) * (1.0 / determination);  // Normalize with determination to smooth movement
    if (direction > 2 * std::numbers::pi) {
        direction -= 2 * std::numbers::pi;
    }

    x += std::cos(direction) * speed;
    y += std::sin(direction) * speed;
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
