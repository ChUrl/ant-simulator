#include "pheromone_map.hpp"

void PheromoneMap::place(unsigned int x, unsigned int y) {
    pheromones[x][y] = 1.0;
}

// Decays the pheromone intensity
void PheromoneMap::update() {
    for (auto x = 0U; x < WIDTH; ++x) {
        for (auto y = 0U; y < HEIGHT; ++y) {
            // TODO: Use defined pheromone decay rate instead of magic number
            pheromones[x][y] = std::max(0.0, pheromones[x][y] - 0.001);
        }
    }
}

// TODO: Represent pheromones as VertexArray directly to skip conversion every frame
sf::VertexArray PheromoneMap::vertex_array() const {
    sf::VertexArray arr = sf::VertexArray(sf::Points, WIDTH * HEIGHT);
    for (auto x = 0U; x < WIDTH; ++x) {
        for (auto y = 0U; y < HEIGHT; ++y) {
            arr[x + y * WIDTH].position = sf::Vector2f(x, y);
            arr[x + y * WIDTH].color = sf::Color(0, 0, 255, 255 * pheromones[x][y]);
        }
    }
    return arr;
}
