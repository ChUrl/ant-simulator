#ifndef H_ANT
#define H_ANT

#include <SFML/Graphics.hpp>
#include <random>

#include "food.hpp"
#include "colony.hpp"
#include "pheromones.hpp"

extern const unsigned short WIDTH;
extern const unsigned short HEIGHT;

const double speed = 1;
const double determination = 25;             // straightness of the path, (0, 1]
const unsigned short pheromone_home_interval = 10; // updates between pheromone-drops
const unsigned short pheromone_food_interval = 5;

const unsigned short view_angle = 45; // angle degrees to each side
const unsigned short view_distance = 25;

class Ant {
  double x, y;
  double direction; // in radians

  Pheromones &pheromones;
  const Colony &colony;

  bool was_home = false; // TODO: Timer-based
  bool has_food = false;
  unsigned short next_pheromone_home_drop = 0;
  unsigned short next_pheromone_food_drop = 0;

  friend class Colony;
  friend class Food;

public:
  sf::CircleShape appearance;

public:
  Ant(Pheromones &pheromones, const Colony &colony, double x, double y);
  Ant(Pheromones &pheromones, const Colony &colony, unsigned short direction);
  Ant(Pheromones &pheromones, const Colony &colony);
  void setAppearance();

  void update();
  bool isOffScreen() const;
  void dropHomePheromone(); // red
  void dropFoodPheromone(); // green
};

#endif
