//
// Created by christoph on 11.04.21.
//

#ifndef ANTSIMULATOR_PHEROMONE_HPP
#define ANTSIMULATOR_PHEROMONE_HPP

#include "world_object.hpp"
#include <SFML/Graphics.hpp>

// TODO: Use percentage
const unsigned int decay = 1;

class Pheromone : public WorldObject {
public:
    // TODO: Use 1.0 to 0.0 double
    unsigned int intensity = 255;

    Pheromone(double x, double y, PheroType type);

    PheroType getPheromoneType() const override;
    void update() override;
};

#endif  //ANTSIMULATOR_PHEROMONE_HPP
