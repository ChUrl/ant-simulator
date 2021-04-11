#ifndef __PHEROMONES_H_
#define __PHEROMONES_H_

#include <vector>
#include <SFML/Graphics.hpp>
#include "pheromone.hpp"

extern const unsigned short WIDTH;
extern const unsigned short HEIGHT;

const unsigned short decay = 1;

class PheromoneMap
{
public:
    std::vector<Pheromone

public:
    PheromoneMap();

    void place(unsigned short x, unsigned short y, sf::Color col);
    sf::Color get(unsigned short x, unsigned short y) const;

    void update();
};

#endif
