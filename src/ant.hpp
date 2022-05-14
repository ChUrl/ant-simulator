#ifndef H_ANT
#define H_ANT

#include <memory>
#include <SFML/Graphics.hpp>
#include <string>

#include "colony.hpp"
#include "food.hpp"
#include "pheromone_map.hpp"
#include "world_object.hpp"

const double speed = 1;
const double determination = 25;              // straightness of the path, (0, 1]
const unsigned short pheromone_interval = 5;  // updates between drops

const unsigned short view_angle = 45;  // angle degrees to each side
const unsigned short view_distance = 25;

class Ant : public WorldObject {
    double direction;  // in radians

    PheromoneMap& pheromones;
    unsigned short next_pheromone_drop = 0;
    PheroType pheromone_type = NONE;  // FOOD, HOME, NONE

public:
    std::vector<std::shared_ptr<WorldObject>> umwelt;

public:
    Ant(PheromoneMap& pheromones, double x, double y);
    Ant(PheromoneMap& pheromones, unsigned short direction);
    explicit Ant(PheromoneMap& pheromones);

    void addToUmwelt(const std::shared_ptr<WorldObject>& object);

    void update() override;
    PheroType getPheromoneType() const override;

    void move();
    void updateAppearance();
    void updatePheromones();
    void dropPheromone();  // red
    void updateUmwelt();
};

#endif
