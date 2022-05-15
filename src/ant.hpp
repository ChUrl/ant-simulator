#ifndef H_ANT
#define H_ANT

#include "colony.hpp"
#include "food.hpp"
#include "main.hpp"
#include "pheromone_map.hpp"
#include "world_object.hpp"
#include <cmath>
#include <iostream>
#include <memory>
#include <numbers>
#include <random>
#include <SFML/Graphics.hpp>
#include <string>

constexpr unsigned int speed = 1;

constexpr unsigned int view_angle = 45;     // angle degrees to each side
constexpr unsigned int view_distance = 25;  // more like smell distance

typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
} direction;

class Ant : public WorldObject {
private:
    // TODO: Switch direction to only N, E, S, W
    direction dir;  // in radians

    // TODO: Should this be here or just global?
    PheromoneMap& pheromones;

    // TODO: Leave continuous trail and remove this
    unsigned int next_pheromone_drop = 0;

public:
    // Contains the WorldObjects (other ants, base, food)
    // TODO: Is this even needed?
    std::vector<std::shared_ptr<WorldObject>> umwelt;

    Ant(PheromoneMap& pheromones, double x, double y);      // Just random direction
    Ant(PheromoneMap& pheromones, unsigned int direction);  // Just random position
    explicit Ant(PheromoneMap& pheromones);                 // All random

    void addToUmwelt(const std::shared_ptr<WorldObject>& object);
    void update() override;
    void move();
    void updateAppearance();
    void dropPheromone();  // red
};

#endif
