#ifndef __FOOD_H_
#define __FOOD_H_

#include "world_object.hpp"
#include <SFML/Graphics.hpp>

class Food : public WorldObject {

public:
    Food(double x, double y);

    void update() override;

    PheroType getPheromoneType() const override;
};

#endif  // __FOOD_H_
