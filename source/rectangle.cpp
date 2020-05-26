#include "rectangle.hpp"
#include "vec2.hpp"
#include <cmath>

Rectangle::Rectangle(Color const& c, Vec2 const& min, Vec2 const& max){
    
    color_ = {c};
    min_ = {min};
    max_ = {max};
}

float Rectangle::circumference() const{
  return 2 * (max_.x_ - min_.x_) + 2 * (max_.y_ - min_.y_);
}