#include "colony.hpp"

Colony::Colony(double x, double y) : WorldObject(x, y, 25, sf::Color::Red) {}

void Colony::update() {}

PheroType Colony::getPheromoneType() const {
    return HOME;
}
