#ifndef H_ANT
#define H_ANT

#include "colony.hpp"
#include "food.hpp"
#include "main.hpp"
#include "pheromone_map.hpp"
#include "world_object.hpp"
#include <iostream>
#include <memory>
#include <random>
#include <SFML/Graphics.hpp>
#include <string>
#include <tuple>

constexpr unsigned int speed = 1;

constexpr unsigned int view_angle = 45;     // angle degrees to each side
constexpr unsigned int view_distance = 25;  // more like smell distance

typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
} direction;

std::tuple<int, int> direction_to_offset(direction dir);

class Ant : public WorldObject {
private:
    direction dir;
    bool has_food = false;

    // TODO: Should this be here or just global?
    PheromoneMap& pheromones;

public:
    // Contains the WorldObjects (other ants?, base, food)
    // TODO: Replace this with direct refereces to base/food
    std::vector<std::shared_ptr<WorldObject>> umwelt;

    Ant(PheromoneMap& pheromones);

    void addToUmwelt(const std::shared_ptr<WorldObject>& object);
    void update() override;
    void move();
    void move_to_base();
    void updateAppearance();
    void dropPheromone();  // red
    bool has_pheromones() override { return false; }
};

#endif
