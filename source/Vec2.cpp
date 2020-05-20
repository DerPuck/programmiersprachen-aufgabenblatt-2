#include "Vec2.hpp"
#include <iostream>
#include <string>

Vec2& Vec2::operator+=(Vec2 const& v) {
    x_ += v.x_;
    y_ += v.y_;
    return *this;
}

Vec2& Vec2::operator-=(Vec2 const& v) {
    x_ -= v.x_;
    y_ -= v.y_;
    return *this;
}

Vec2& Vec2::operator*=(float s) {
    x_ *= s;
    y_ *= s;
    return *this;
}
Vec2& Vec2::operator /=(float s) {
    if(s == 0){
        std::cout << " Divide / 0 geht nicht du Genie ;-)" << std::endl;
        return *this;
    }
    else {
      x_ /= s;
      y_ /= s;
      return *this;
    }
}

Vec2 operator +( Vec2 const & u, Vec2 const & v) {
  Vec2 nVec2{ u.x_, u.y_};
  nVec2 += v;
  return nVec2;
}