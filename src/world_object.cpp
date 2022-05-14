#include "world_object.hpp"

WorldObject::WorldObject(double x, double y, unsigned short radius, sf::Color color)
  : x(x), y(y), radius(radius) {
    appearance = sf::CircleShape(radius);
    appearance.setFillColor(color);
    appearance.setPosition(x, y);
    appearance.setOrigin(radius, radius);
}

bool WorldObject::isOffScreen() const {
    return x < 0 || x > WIDTH || y < 0 || y > HEIGHT;
}

bool WorldObject::collides(const WorldObject& other) const {
    return distance(other) < radius + other.radius;
}

double WorldObject::distance(const WorldObject& other) const {
    const double dx = std::abs(x - other.x);
    const double dy = std::abs(y - other.y);
    return std::sqrt(dx * dx + dy * dy);
}

double WorldObject::angle(const WorldObject& other) const {
    const double dy = std::abs(y - other.y);
    return std::asin(dy / distance(other));
}
