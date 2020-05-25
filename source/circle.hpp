#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "color.hpp"
#include "vec2.hpp"

class Circle {
  Circle(Color const& c, Vec2 center , float r);

  Color color_;
  Vec2 cpoint_;
  float radius_;
  
};

#endif