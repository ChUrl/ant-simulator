#ifndef __COLONY_H_
#define __COLONY_H_

#include <SFML/Graphics.hpp>
#include "world_object.hpp"

class Colony : public WorldObject
{

public:
    Colony(double x, double y);

    void update() override;

    sf::Color getPheromoneType() const override;
};

#endif // __COLONY_H_
