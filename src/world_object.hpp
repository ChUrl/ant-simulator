#ifndef __WORLD_OBJECT_H_
#define __WORLD_OBJECT_H_

#include <cmath>
#include <SFML/Graphics.hpp>

// TODO: Move definitions to header and use constexpr/macro
extern const unsigned int WIDTH;
extern const unsigned int HEIGHT;

// TODO: Just use FOOD
enum PheroType {
    FOOD,
    HOME,
    NONE
};

class WorldObject {
protected:
    double x, y;
    const unsigned int radius;

    WorldObject(double x, double y, unsigned int radius, sf::Color color);

public:
    sf::CircleShape appearance;

    bool isOffScreen() const;
    bool collides(const WorldObject& other) const;
    double distance(const WorldObject& other) const;
    double angle(const WorldObject& other) const;

    // TODO: Switch to only food pheromones
    virtual PheroType getPheromoneType() const = 0;
    virtual void update() = 0;  // pure virtual: has to be overridden
};

#endif  // __OBJECT_H_
