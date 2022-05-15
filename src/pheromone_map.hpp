#ifndef __PHEROMONES_H_
#define __PHEROMONES_H_

#include "main.hpp"
#include <array>
#include <SFML/Graphics.hpp>

class PheromoneMap {
public:
    std::array<std::array<double, HEIGHT>, WIDTH> pheromones;

    void place(unsigned int x, unsigned int y);
    void update();
    sf::VertexArray vertex_array() const;
};

#endif
