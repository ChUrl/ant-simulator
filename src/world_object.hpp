#ifndef __OBJECT_H_
#define __OBJECT_H_

#include <cmath>
#include <SFML/Graphics.hpp>

extern const unsigned short WIDTH;
extern const unsigned short HEIGHT;

class WorldObject
{
protected:
    double x, y;
    const unsigned short radius;

public:
    sf::CircleShape appearance;

protected:
    WorldObject(double x, double y, unsigned short radius, sf::Color color);

public:
    bool isOffScreen() const; // virtual: late-binding, no static linkage
    bool collides(const WorldObject& other) const;

    double distance(const WorldObject& other) const;

    double angle(const WorldObject& other) const;

    virtual void update() = 0; // pure virtual: has to be overridden
    virtual sf::Color getPheromoneType() const = 0;
};

#endif // __OBJECT_H_
