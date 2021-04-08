#ifndef __FOOD_H_
#define __FOOD_H_

#include <SFML/Graphics.hpp>

class Ant;

class Food {
  double x, y;

public:
  sf::CircleShape appearance;

public:
  Food(double x, double y);

  bool antHasFood(const Ant& ant) const;
};

#endif // __FOOD_H_
