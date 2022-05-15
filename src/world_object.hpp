#ifndef __WORLD_OBJECT_H_
#define __WORLD_OBJECT_H_

#include "main.hpp"
#include <cmath>
#include <SFML/Graphics.hpp>

class WorldObject {
protected:
    unsigned int x, y;
    const unsigned int radius;

    WorldObject(unsigned int x, unsigned int y, unsigned int radius, sf::Color color);

public:
    sf::CircleShape appearance;

    bool isOffScreen() const;
    bool collides(const WorldObject& other) const;
    double distance(const WorldObject& other) const;
    double angle(const WorldObject& other) const;

    virtual void update() = 0;  // pure virtual: has to be overridden
};

#endif  // __OBJECT_H_
