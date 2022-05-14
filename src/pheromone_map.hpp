#ifndef __PHEROMONES_H_
#define __PHEROMONES_H_

#include "ant.hpp"
#include "pheromone.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class Ant;

class PheromoneMap {
public:
    // TODO: Use fixed size matrix (and only int locations) for this, currently it's just slow
    std::vector<Pheromone> pheromones;

    // TODO: Move this to ant
    std::vector<Pheromone> getInVision(const Ant& ant, PheroType type, unsigned short radius);
    void place(double x, double y, PheroType type);
    void update();
};

#endif
