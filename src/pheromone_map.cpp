#include <iostream>
#include "pheromone_map.hpp"
#include "ant.hpp"

void PheromoneMap::place(double x, double y, PheroType type) {
    pheromones.emplace_back(x, y, type);
}

std::vector<Pheromone> PheromoneMap::getInVision(const Ant& ant, PheroType type, unsigned short radius) {
    std::vector<Pheromone> umwelt;

    for (const Pheromone& pheromone : pheromones) {
        if (pheromone.getPheromoneType() == type
            && pheromone.distance(ant) <= radius) {
            umwelt.push_back(pheromone);
        }
    }

    return umwelt;
}

void PheromoneMap::update() {
    for (size_t i = 0; i < pheromones.size(); ++i) {
        if (pheromones[i].appearance.getFillColor().a == 0) {
//            pheromones.erase(pheromones.begin() + i);
        }
    }
}
