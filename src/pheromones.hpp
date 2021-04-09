#ifndef __PHEROMONES_H_
#define __PHEROMONES_H_

#include <SFML/Graphics.hpp>

extern const unsigned short WIDTH;
extern const unsigned short HEIGHT;

const unsigned short decay = 1;

class Pheromones
{
public:
    sf::VertexArray map = sf::VertexArray(sf::PrimitiveType::Points, WIDTH * HEIGHT);

public:
    Pheromones();

    void place(unsigned short x, unsigned short y, sf::Color col);

    void update();
};

#endif
