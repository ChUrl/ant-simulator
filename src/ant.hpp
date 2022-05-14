#ifndef H_ANT
#define H_ANT

#include "colony.hpp"
#include "food.hpp"
#include "pheromone_map.hpp"
#include "world_object.hpp"
#include <cmath>
#include <iostream>
#include <memory>
#include <numbers>
#include <random>
#include <SFML/Graphics.hpp>
#include <string>

const double speed = 1;
const double determination = 25;            // straightness of the path
const unsigned int pheromone_interval = 5;  // how many updates between drops

const unsigned int view_angle = 45;     // angle degrees to each side
const unsigned int view_distance = 25;  // more like smell distance

class Ant : public WorldObject {
    double direction;  // in radians

    // TODO: Should this be here or just global?
    PheromoneMap& pheromones;
    unsigned int next_pheromone_drop = 0;
    PheroType pheromone_type = NONE;  // FOOD, HOME, NONE

public:
    // TODO: Why is this stored here? I guess it can be removed
    std::vector<std::shared_ptr<WorldObject>> umwelt;

public:
    Ant(PheromoneMap& pheromones, double x, double y);
    Ant(PheromoneMap& pheromones, unsigned int direction);
    explicit Ant(PheromoneMap& pheromones);

    // TODO: Regarding umwelt
    void addToUmwelt(const std::shared_ptr<WorldObject>& object);

    void update() override;
    PheroType getPheromoneType() const override;

    void move();
    void updateAppearance();
    void updatePheromones();
    void dropPheromone();  // red

    // TODO: Regarding umwelt
    void updateUmwelt();
};

#endif
