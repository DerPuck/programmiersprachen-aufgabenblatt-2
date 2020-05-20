#include "Vec2.hpp"

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

