//
// Created by christoph on 11.04.21.
//

#include "pheromone.hpp"

Pheromone::Pheromone(double x, double y, PheroType type)
  : WorldObject(x, y, 2, sf::Color::Transparent) {
    if (type == HOME) {
        appearance.setFillColor(sf::Color::Red);
    } else if (type == FOOD) {
        appearance.setFillColor(sf::Color::Green);
    } else {
        appearance.setFillColor(sf::Color::Transparent);
    }
}

PheroType Pheromone::getPheromoneType() const {
    if (appearance.getFillColor() == sf::Color::Red) {
        return HOME;
    }
    if (appearance.getFillColor() == sf::Color::Green) {
        return FOOD;
    }
    return NONE;
}

void Pheromone::update() {
    intensity = std::max(0U, intensity - decay);
    appearance.setFillColor(sf::Color(
      appearance.getFillColor().r,
      appearance.getFillColor().g,
      appearance.getFillColor().b,
      intensity));
}
