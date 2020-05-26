#include "rectangle.hpp"
#include "vec2.hpp"
#include "window.hpp"
#include <cmath>

Rect::Rect(Color const& c, Vec2 const& min, Vec2 const& max){
    
    color_ = {c};
    min_ = {min};
    max_ = {max};
}

Rect::Rect(){
    color_ = {0.1f,0.1f,0.1f};
    min_ = {0.0f,0.0f};
    max_ = {100.0f,100.0f};
}

float Rect::circumference() const{
  return 2 * (max_.x_ - min_.x_) + 2 * (max_.y_ - min_.y_);
}

void Rect::draw(Window const& win) const {
    win.draw_line(max_.x_, max_.y_, min_.x_, max_.y_, color_.r, color_.g, color_.b);
    win.draw_line(max_.x_, max_.y_, max_.x_, min_.y_, color_.r, color_.g, color_.b);
    win.draw_line(min_.x_, min_.y_, min_.x_, max_.y_, color_.r, color_.g, color_.b);
    win.draw_line(min_.x_, min_.y_, max_.x_, min_.y_, color_.r, color_.g, color_.b);
}
