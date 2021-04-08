#include "colony.hpp"
#include "ant.hpp"

Colony::Colony(double x, double y)
  : x(x), y(y) {
  appearance = sf::CircleShape(25);
  appearance.setFillColor(sf::Color::Red);
  appearance.setPosition(x - appearance.getRadius(), y - appearance.getRadius());
}

// TODO: don't use appearance for this, add radius field
bool Colony::antIsHome(const Ant& ant) const {
  return ant.x > x - appearance.getRadius() && ant.x < x + appearance.getRadius()
    && ant.y > y - appearance.getRadius() && ant.y < y + appearance.getRadius();
}
