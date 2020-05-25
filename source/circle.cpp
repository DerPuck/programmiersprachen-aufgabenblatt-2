#include "circle.hpp"
#include "vec2.hpp"
#include <cmath>

Circle::Circle(Color const& c, Vec2 center , float radius){
    
  color_ = {c};
  center_ = {center};
  radius_ = {radius};
}

float Circle::circumference() const{
  return 2 * M_PI * radius_;
}
