#ifndef __PHEROMONES_H_
#define __PHEROMONES_H_

#include <vector>
#include <SFML/Graphics.hpp>
#include "pheromone.hpp"

class Ant;

class PheromoneMap
{
public:
    std::vector<Pheromone> pheromones;

public:
    void place(double x, double y, PheroType type);
    std::vector<Pheromone> getInVision(const Ant& ant, PheroType type, unsigned short radius);

    void update();
};

#endif
