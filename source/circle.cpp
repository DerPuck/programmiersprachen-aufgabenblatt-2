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

Circ::Circ(Color const& c, Vec2 center , float radius){
    
  color_ = {c};
  center_ = {center};
  radius_ = {radius};
}



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
