#ifndef __PHEROMONES_H_
#define __PHEROMONES_H_

#include "main.hpp"
#include <array>

class PheromoneMap {
public:
    std::array<std::array<double, HEIGHT>, WIDTH> pheromones;

    void place(double x, double y);
    void update();
    void draw();
};

#endif
