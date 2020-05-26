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

  void draw(Window const& win, float thickness) const;

  bool is_inside(Vec2 const& point) const;


  private:
  //Color col; //Does not identify the Color class so i made this. no idea thy but it works :)
  
  Color color_ = {};
  Vec2 min_ = {0.0f, 0.0f};
  Vec2 max_ = {0.0f, 0.0f};
  
};

#endif