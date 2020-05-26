#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "color.hpp"
#include "vec2.hpp"
#include "window.hpp"

class Circ {
  public: 
  Circ(Color const& c, Vec2 const& center , float const& radius);
  Circ();

  float circumference() const;

  void draw(Window const& win, float thickness) const;

  private:
  Color color_;
  Vec2 center_;
  float radius_;

};

#endif