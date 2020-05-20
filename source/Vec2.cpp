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

Vec2& Vec2::operator*=(float s) {
    x_ *= s;
    y_ *= s;
    return *this;
}
/*Vec2& Vec2::operator /=(float s) {
    x_ /= s;;
    y_ /= s;
    return *this;
}*/