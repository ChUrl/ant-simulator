#ifndef __OBJECT_H_
#define __OBJECT_H_

#include <SFML/Graphics.hpp>

class Object {
protected:
  double x, y;
  const unsigned short radius;

  sf::CircleShape appearance;

protected:
  Object(double x, double y, unsigned short radius);

public:
  virtual bool collide(const Object& other);
};

#endif // __OBJECT_H_
