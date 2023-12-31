#ifndef __COLONY_H_
#define __COLONY_H_

#include "world_object.hpp"
#include <SFML/Graphics.hpp>

class Colony : public WorldObject {
public:
    Colony(double x, double y);

    void update() override;
    bool has_pheromones() override { return false; }
};

#endif  // __COLONY_H_
