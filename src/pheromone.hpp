//
// Created by christoph on 11.04.21.
//

#ifndef ANTSIMULATOR_PHEROMONE_HPP
#define ANTSIMULATOR_PHEROMONE_HPP

#include "world_object.hpp"
#include <SFML/Graphics.hpp>

const unsigned short decay = 1;

class Pheromone : public WorldObject {
public:
    unsigned short intensity = 255;

public:
    Pheromone(double x, double y, PheroType type);

    PheroType getPheromoneType() const override;
    void update() override;
};

#endif  //ANTSIMULATOR_PHEROMONE_HPP
