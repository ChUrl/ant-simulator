#include "ant.hpp"
#include "pheromones.hpp"
#include <cmath>
#include <iostream>
#include <numbers>

Ant::Ant(Pheromones &pheromones, const Colony &colony, double x, double y)
    : x(x), y(y), pheromones(pheromones), colony(colony) {
  std::random_device rd;  // obtain a random number from hardware
  std::mt19937 gen(rd()); // seed the generator

  std::uniform_real_distribution<> degree_distribution(0, 2 * std::numbers::pi);
  direction = degree_distribution(gen);

  setAppearance();
}

Ant::Ant(Pheromones &pheromones, const Colony &colony, unsigned short direction)
    : direction(direction), pheromones(pheromones), colony(colony) {
  std::random_device device;        // obtain a random number from hardware
  std::mt19937 generator(device()); // seed the generator

  std::uniform_int_distribution<> width_distribution(0, WIDTH);
  x = width_distribution(generator);

  std::uniform_int_distribution<> height_distribution(0, HEIGHT);
  y = height_distribution(generator);

  setAppearance();
}

Ant::Ant(Pheromones &pheromones, const Colony &colony)
  : pheromones(pheromones), colony(colony) {
  std::random_device device;        // obtain a random number from hardware
  std::mt19937 generator(device()); // seed the generator

  std::uniform_int_distribution<> width_distribution(0, WIDTH);
  x = width_distribution(generator);

  std::uniform_int_distribution<> height_distribution(0, HEIGHT);
  y = height_distribution(generator);

  std::uniform_real_distribution<> degree_distribution(0, 2 * std::numbers::pi);
  direction = degree_distribution(generator);

  setAppearance();
}

void Ant::setAppearance() {
  appearance = sf::CircleShape(2);
  appearance.setFillColor(sf::Color::Black);
  appearance.setPosition(x - appearance.getRadius(), y - appearance.getRadius());
}

void Ant::update() {
  // TODO: save the generator for each ant
  std::random_device device;        // obtain a random number from hardware
  std::mt19937 generator(device()); // seed the generator

  // Move
  std::uniform_real_distribution<> degree_distribution(-std::numbers::pi,
                                                       std::numbers::pi);

  direction += degree_distribution(generator) * (1 / determination);
  if (direction > 2 * std::numbers::pi) {
    direction -= 2 * std::numbers::pi;
  }

  x += std::cos(direction) * speed;
  y += std::sin(direction) * speed;

  // Update appearance
  appearance.setPosition(x - appearance.getRadius(), y - appearance.getRadius());
  if (was_home) {
    appearance.setFillColor(sf::Color::Red);
  }
  if (has_food) {
    appearance.setFillColor(sf::Color::Green);
  }

  // Respect borders
  if (isOffScreen()) {
    direction += std::numbers::pi / 2;

    x += std::cos(direction) * speed;
    y += std::sin(direction) * speed;

    appearance.setPosition(x - appearance.getRadius(), y - appearance.getRadius());

    return;
  }

  // Visited Home?
  if (!was_home && colony.antIsHome(*this)) {
    was_home = true;
    std::cout << "Ant has come home!" << std::endl;
  }

  // Pheromones
  if (was_home && next_pheromone_home_drop == 0) {
    dropHomePheromone();
    next_pheromone_home_drop = pheromone_home_interval + 1;
  }
  next_pheromone_home_drop = std::max(0, next_pheromone_home_drop - 1);

  if (has_food && next_pheromone_food_drop == 0) {
    dropFoodPheromone();
    next_pheromone_food_drop = pheromone_food_interval + 1;
  }
  next_pheromone_food_drop = std::max(0, next_pheromone_food_drop - 1);
}

bool Ant::isOffScreen() const {
  return x < 0 || x > WIDTH || y < 0 || y > HEIGHT;
}

void Ant::dropHomePheromone() {
  if (isOffScreen()) {
    std::cout << "Ant can't drop Pheromones offscreen!" << std::endl;
    return;
  }

  // TODO: Replace this with null-safe funtion
  pheromones.map[((short)y) * WIDTH + ((short)x)].color = sf::Color::Red;
  // pheromones.map[((short)y - 1) * WIDTH + ((short)x)].color = sf::Color::Red;
  // pheromones.map[((short)y + 1) * WIDTH + ((short)x)].color = sf::Color::Red;
  // pheromones.map[((short)y) * WIDTH + ((short)x - 1)].color = sf::Color::Red;
  // pheromones.map[((short)y) * WIDTH + ((short)x + 1)].color = sf::Color::Red;
}

void Ant::dropFoodPheromone() {
  if (isOffScreen()) {
    std::cout << "Ant can't drop Pheromones offscreen!" << std::endl;
    return;
  }

  pheromones.map[((short)y) * WIDTH + ((short)x)].color = sf::Color::Green;
}
