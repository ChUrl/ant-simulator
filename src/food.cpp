#include "food.hpp"
#include "ant.hpp"

Food::Food(double x, double y)
  : x(x), y(y) {
  appearance = sf::CircleShape(15);
  appearance.setFillColor(sf::Color::Green);
  appearance.setPosition(x - appearance.getRadius(), y - appearance.getRadius());
}

bool Food::antHasFood(const Ant &ant) const {
  return ant.x > x - appearance.getRadius() && ant.x < x + appearance.getRadius()
    && ant.y > y - appearance.getRadius() && ant.y < y + appearance.getRadius();
}
