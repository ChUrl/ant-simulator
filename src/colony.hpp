#ifndef __COLONY_H_
#define __COLONY_H_

#include <SFML/Graphics.hpp>

class Ant; // Colony and Ant can't include eachother so forward-declare

class Colony {
  double x, y;

public:
  sf::CircleShape appearance;

public:
  Colony(double x, double y);

  bool antIsHome(const Ant& ant) const;
};

#endif // __COLONY_H_
