#ifndef ACID_INCLUDE_ACID_MATH_H_
#define ACID_INCLUDE_ACID_MATH_H_

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <cmath>

#define PI 3.14159265


class ACIDMath {
  public:
    static void get_unit_b2Vec2(b2Vec2& vector);
    static void get_unit_Vector2f(sf::Vector2f vector);
    static float get_angle_from_b2Vec(b2Vec2& vector);
    static float get_angle_from_Vector2f(sf::Vector2f vector);
};

#endif  // ACID_INCLUDE_ACID_MATH_H_
