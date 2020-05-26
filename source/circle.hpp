#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "color.hpp"
#include "vec2.hpp"

class Circle {
  public: Circle(Color const& c, Vec2 center , float radius);

  Color color_;
  Vec2 center_;
  float radius_;

  float circumference() const;

};

#endif