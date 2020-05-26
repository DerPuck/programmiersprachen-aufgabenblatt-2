#include "circle.hpp"
#include "vec2.hpp"
#include "window.hpp"
#include "mat2.hpp"
#include <cmath>

Circ::Circ(){
  color_ = {0.1f,0.1f,0.1f};
  center_ = {0.0f, 0.0f};
  radius_ = {1};
  
}

Circ::Circ(Color const& c, Vec2 const& center , float const& radius):
    
  color_ {c},
  center_ {center},
  radius_ {radius}
{}

float Circ::circumference() const{
  return 2 * M_PI * radius_;
}

void Circ::draw(Window const& win) const {
  int seg = 200;
  Vec2 start {center_.x_, center_.y_ + radius_};
  int i = 1;
  while (i <= seg)
  {
      Vec2 nstart = start;
      nstart -= center_;
      nstart = make_rotation_mat2(2 * M_PI/seg) * nstart;
      nstart += center_;
      win.draw_line(start.x_, start.y_, nstart.x_, nstart.y_, color_.r, color_.g, color_.b);
      start = nstart;
      ++i;
  }
}

void Circ::draw(Window const& win, float thickness) const {
  int seg = 200;
  Vec2 start {center_.x_, center_.y_ + radius_};
  int i = 1;
  while (i <= seg)
  {
      Vec2 nstart = start;
      nstart -= center_;
      nstart = make_rotation_mat2(2 * M_PI/seg) * nstart;
      nstart += center_;
      win.draw_line(start.x_, start.y_, nstart.x_, nstart.y_, color_.r, color_.g, color_.b, thickness);
      start = nstart;
      ++i;
  }
}

bool Circ::is_inside(Vec2 const& point) const{
  Vec2 zw {point.x_ - center_.x_, point.y_ - center_.y_};
  if(fabs(zw.x_) + fabs(zw.y_) < radius_){
    return true;
  }
  else
  {
    return false;
  }
  
}