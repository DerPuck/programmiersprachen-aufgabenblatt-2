#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "color.hpp"
#include "vec2.hpp"
#include "window.hpp"

class Circ {
  public: 
  Circ(Color const& c, Vec2 center , float radius);
  Circ();

  Color color_;
  Vec2 center_;
  float radius_;

  float circumference() const;

  void draw(Window const& win) const;


};

#endif