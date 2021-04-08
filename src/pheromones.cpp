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

void Pheromones::update() {
  for (int i = 0; i < WIDTH * HEIGHT; ++i) {
    // if (map[i].color != sf::Color::White) {
      map[i].color -= sf::Color(decay, decay, decay, decay);
    // }
  }
}
