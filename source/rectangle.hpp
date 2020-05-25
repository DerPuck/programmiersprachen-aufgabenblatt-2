#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "color.hpp"
#include "vec2.hpp"

class Rectangle {
  Rectangle(Color const& c, Vec2 const& min, Vec2 const& max);

  Color color_;
  Vec2 min_ = {0.0f, 0.0f};
  Vec2 max_ = {0.0f, 0.0f};

};

#endif