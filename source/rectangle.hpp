#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "color.hpp"
#include "vec2.hpp"
#include "window.hpp"

class Rect {
  public: 
  Rect(Color const& c, Vec2 const& min, Vec2 const& max);
  Rect();

  float circumference() const;

  void draw(Window const& win) const;

  private:
  Color color_;
  Vec2 min_ = {0.0f, 0.0f};
  Vec2 max_ = {0.0f, 0.0f};
  

};

#endif