#include "mat2.hpp"

//Aufgabe2.5
Mat2& Mat2::operator *=(Mat2 const& m) {
    float temp_00 = e_00;
    float temp_01 = e_01;
    float temp_10 = e_10;
    float temp_11 = e_11;
    e_00 = temp_00 * m.e_00 + temp_10 * m.e_01; 
    e_10 = temp_00 * m.e_10 + temp_10 * m.e_11;
    e_01 = temp_01 * m.e_00 + temp_11 * m.e_01;
    e_11 = temp_01 * m.e_10 + temp_11 * m.e_11;
    return *this;
}
//Aufgabe2.5
Mat2 operator *( Mat2 const & m1 , Mat2 const & m2) {
  Mat2 nMat2 {m1};
  nMat2 *= m2;
  return nMat2;
}