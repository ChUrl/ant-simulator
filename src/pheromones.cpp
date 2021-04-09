#include "pheromones.hpp"

extern const unsigned short WIDTH;
extern const unsigned short HEIGHT;

Pheromones::Pheromones() {
    for (unsigned short y = 0; y < HEIGHT; ++y) {
        for (unsigned short x = 0; x < WIDTH; ++x) {
            map[y * WIDTH + x].position.x = x;
            map[y * WIDTH + x].position.y = y;
            map[y * WIDTH + x].color = sf::Color(0, 0, 0, 0);
        }
    }
}

void Pheromones::place(unsigned short x, unsigned short y, sf::Color col) {
    map[y * WIDTH + x].color = col;
    map[(y + 1) * WIDTH + x].color = col;
    map[(y - 1) * WIDTH + x].color = col;
    map[y * WIDTH + (x + 1)].color = col;
    map[y * WIDTH + (x - 1)].color = col;
}

void Pheromones::update() {
    for (int i = 0; i < WIDTH * HEIGHT; ++i) {
        map[i].color -= sf::Color(decay, decay, decay, decay);
    }
    for (int x = 0; x < WIDTH; ++x) {
        map[(HEIGHT / 2) * WIDTH + x].color = sf::Color::Black;
    }
    for (int y = 0; y < HEIGHT; ++y) {
        map[y * WIDTH + (WIDTH / 2)].color = sf::Color::Black;
    }
}
