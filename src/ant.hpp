#ifndef H_ANT
#define H_ANT

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

#include "world_object.hpp"
#include "pheromones.hpp"
#include "colony.hpp"
#include "food.hpp"

const double speed = 1;
const double determination = 25;             // straightness of the path, (0, 1]
const unsigned short pheromone_interval = 5; // updates between drops

const unsigned short view_angle = 45; // angle degrees to each side
const unsigned short view_distance = 25;

class Ant : public WorldObject
{
    double direction; // in radians

    Pheromones& pheromones;
    unsigned short next_pheromone_drop = 0;
    sf::Color pheromone_type = sf::Color::Transparent; // ANT, HOME, FOOD

public:
    std::vector<std::shared_ptr<WorldObject>> umwelt;

public:
    Ant(Pheromones& pheromones, double x, double y);
    Ant(Pheromones& pheromones, unsigned short direction);
    explicit Ant(Pheromones& pheromones);

    void addToUmwelt(std::shared_ptr<WorldObject> object);

    void update() override;
    sf::Color getPheromoneType() const override;

    void move();
    void updateAppearance();
    void updatePheromones();
    void dropPheromone(); // red
    void updateUmwelt();
};

#endif
