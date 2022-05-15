#include "pheromone_map.hpp"

void PheromoneMap::place(double x, double y) {
    pheromones[x][y] = 1.0;
}

// Decays the pheromone intensity
void PheromoneMap::update() {
    for (auto x = 0; x < WIDTH; ++x) {
        for (auto y = 0; y < HEIGHT; ++y) {
            // TODO: Use defined pheromone decay rate instead of magic 0.01
            pheromones[x][y] = std::max(0.0, pheromones[x][y] - 0.01);
        }
    }
}

void PheromoneMap::draw() {
    // TODO: This should convert the 2d pheromone map to a sfml VertexArray to be drawn to the window (below the ants/base/food)
}
