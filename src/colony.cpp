#include "colony.hpp"

Colony::Colony(double x, double y) : WorldObject(x, y, 25, sf::Color::Red) {}

void Colony::update() {}

sf::Color Colony::getPheromoneType() const {
    return sf::Color::Red;
}
