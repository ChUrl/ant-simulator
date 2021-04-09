#include "food.hpp"

Food::Food(double x, double y) : WorldObject(x, y, 15, sf::Color::Green) {}

void Food::update() {}

sf::Color Food::getPheromoneType() const {
    return sf::Color::Green;
}
