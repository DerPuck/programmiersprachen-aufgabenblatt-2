#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

#include <cmath>



//Aufgabe2.2
TEST_CASE ("describe_Vec2", "[Vec2]")
{
  Vec2 a = {};
  Vec2 b {5.1f, -9.3f};
REQUIRE (a.x_ == 0.0f);
REQUIRE (a.y_ == 0.0f);
REQUIRE (5.1f == Approx (b.x_));
REQUIRE (-9.3f == Approx (b.y_));
}

//Aufgabe2.3
TEST_CASE ("describe_+Vec2", "[Vec2]")
{
  Vec2 a = {};
  Vec2 b {5.1f, -9.3f};
  a += b;
REQUIRE (a.x_ == Approx (5.1f));
REQUIRE (a.y_ == Approx(-9.3f));
  Vec2 c {-3.5f, 2.5f};
  b += c;
REQUIRE (b.x_ == Approx (1.6f));
REQUIRE (b.y_ == Approx(-6.8f));
}

TEST_CASE ("describe_-Vec2", "[Vec2]")
{
  Vec2 a = {};
  Vec2 b {5.1f, -9.3f};
  a -= b;
REQUIRE (a.x_ == Approx (-5.1f));
REQUIRE (a.y_ == Approx(9.3f));
  Vec2 c {-3.5f, 2.5f};
  b -= c;
REQUIRE (b.x_ == Approx (8.6f));
REQUIRE (b.y_ == Approx(-11.8f));
}

TEST_CASE ("describe_*Vec2", "[Vec2]")
{
  Vec2 a = {};
  Vec2 b {5.1f, -9.3f};
  a *= 0.0f;
REQUIRE (a.x_ == Approx (0.0f));
REQUIRE (a.y_ == Approx(0.0f));
  b *= 10.0f;
REQUIRE (b.x_ == Approx(51.0f));
REQUIRE (b.y_ == Approx(-93.0f));
  b *= -10.0f;
REQUIRE (b.x_ == Approx(-510.0f));
REQUIRE (b.y_ == Approx(930.0f));
}

TEST_CASE ("describe_/Vec2", "[Vec2]")
{
  Vec2 a = {};
  Vec2 b {5.1f, -9.3f};
  Vec2 c {5.1f, -9.3f};

  a /= 1.0f;
REQUIRE (a.x_ == Approx (0.0f));
REQUIRE (a.y_ == Approx(0.0f));
  b /= 0.0f;
REQUIRE (b.x_ == Approx (5.1f));
REQUIRE (b.y_ == Approx(-9.3f));
  c /= -10.0f;
REQUIRE (c.x_ == Approx(-0.51));
REQUIRE (c.y_ == Approx(0.93));
}

//Aufgabe2.4
TEST_CASE ("describe_freefunction+Vec2", "[Vec2]")
{
  Vec2 a = {};
  Vec2 b {5.1f, -9.3f};
  Vec2 n1 = a + b;
REQUIRE (n1.x_ == Approx(5.1f));
REQUIRE (n1.y_ == Approx(-9.3f));
  Vec2 c {-3.5f, 2.5f};
  Vec2 n2 = b + c;
REQUIRE (n2.x_ == Approx (1.6f));
REQUIRE (n2.y_ == Approx(-6.8f));
}

TEST_CASE ("describe_freefunction-Vec2", "[Vec2]")
{
  Vec2 a = {};
  Vec2 b {5.1f, -9.3f};
  Vec2 n1 = a - b;
REQUIRE (n1.x_ == Approx (-5.1f));
REQUIRE (n1.y_ == Approx(9.3f));
  Vec2 c {-3.5f, 2.5f};
  Vec2 n2 = b - c;
REQUIRE (n2.x_ == Approx (8.6f));
REQUIRE (n2.y_ == Approx(-11.8f));
}

TEST_CASE ("describe_freefunction*Vec2", "[Vec2]")
{
  Vec2 a = {};
  Vec2 b {5.1f, -9.3f};
  Vec2 n1 = a * 10;
REQUIRE (n1.x_ == Approx (0.0f));
REQUIRE (n1.y_ == Approx(0.0f));
  Vec2 c {-3.5f, 2.5f};
  Vec2 n2 = c * -10;
REQUIRE (n2.x_ == Approx (35.0f));
REQUIRE (n2.y_ == Approx(-25.0f));
  Vec2 d {-3.5f, 2.5f};
  Vec2 n3 = d * 0;
REQUIRE (n3.x_ == Approx (0.0f));
REQUIRE (n3.y_ == Approx(0.0f));
}

TEST_CASE ("describe_freefunction/Vec2", "[Vec2]")
{
  Vec2 a = {};
  Vec2 b {5.1f, -9.3f};
  Vec2 n1 = a / 10;
REQUIRE (n1.x_ == Approx (0.0f));
REQUIRE (n1.y_ == Approx(0.0f));
  Vec2 c {-3.5f, 2.5f};
  Vec2 n2 = c / -10;
REQUIRE (n2.x_ == Approx (0.35f));
REQUIRE (n2.y_ == Approx(-0.25f));
  Vec2 e {-3.5f, 2.5f};
  Vec2 n3 = e / 0;
REQUIRE (n3.x_ == Approx (-3.5f));
REQUIRE (n3.y_ == Approx(2.5f));
}

TEST_CASE ("describe_freefunction*doubleVec2", "[Vec2]")
{
  Vec2 a = {};
  Vec2 b {5.1f, -9.3f};
  Vec2 n1 = 10 * a;
REQUIRE (n1.x_ == Approx (0.0f));
REQUIRE (n1.y_ == Approx(0.0f));
  Vec2 c {-3.5f, 2.5f};
  Vec2 n2 = -10 * c;
REQUIRE (n2.x_ == Approx (35.0f));
REQUIRE (n2.y_ == Approx(-25.0f));
  Vec2 d {-3.5f, 2.5f};
  Vec2 n3 = 0 * d;
REQUIRE (n3.x_ == Approx (0.0f));
REQUIRE (n3.y_ == Approx(0.0f));
}

//Aufgabe2.5
TEST_CASE ("describe_*Mat2", "[Mat2]")
{
Mat2 a {4.0f,5.0f,3.0f,7.0f};
Mat2 b {-1.0f,0.0f,-5.0f,2.0f};
Mat2 c {0.0f,0.0f,0.0f,0.0f};
a *= b;
REQUIRE (a.e_00 == Approx (-29.0f));
REQUIRE (a.e_10== Approx(10.0f));
REQUIRE (a.e_01 == Approx (-38.0f));
REQUIRE (a.e_11== Approx(14.0f));
b *= c;
REQUIRE (b.e_00 == Approx (0.0f));
REQUIRE (b.e_10== Approx(0.0f));
REQUIRE (b.e_01 == Approx (0.0f));
REQUIRE (b.e_11== Approx(0.0f));
}

TEST_CASE ("describe_freefunction*Mat2", "[Mat2]")
{
Mat2 a {4.0f,5.0f,3.0f,7.0f};
Mat2 b {-1.0f,0.0f,-5.0f,2.0f};
Mat2 c {0.0f,0.0f,0.0f,0.0f};
Mat2 d = a * b;
REQUIRE (d.e_00 == Approx (-29.0f));
REQUIRE (d.e_10== Approx(10.0f));
REQUIRE (d.e_01 == Approx (-38.0f));
REQUIRE (d.e_11== Approx(14.0f));
Mat2 f = b * c;
REQUIRE (f.e_00 == Approx (0.0f));
REQUIRE (f.e_10== Approx(0.0f));
REQUIRE (f.e_01 == Approx (0.0f));
REQUIRE (f.e_11== Approx(0.0f));
}

//Aufgabe2.6
TEST_CASE ("describe_Vec2*Mat2", "[Mat2]")
{
Mat2 a {4.0f,5.0f,3.0f,7.0f};
Mat2 b {-1.0f,0.0f,-5.0f,2.0f};
Mat2 c {0.0f,0.0f,0.0f,0.0f};
Vec2 d {2.0f,4.0f};
Vec2 e {0.0f,0.0f};
Vec2 v1 = a * d;
REQUIRE (v1.x_ == Approx (28.0f));
REQUIRE (v1.y_== Approx(34.0f));
Vec2 v2 = b * e;
REQUIRE (v2.x_ == Approx (0.0f));
REQUIRE (v2.y_== Approx(0.0f));
Vec2 v3 = c * d;
REQUIRE (v3.x_ == Approx (0.0f));
REQUIRE (v3.y_== Approx(0.0f));
}

TEST_CASE ("describe_DeterminanteMat2", "[Det]")
{
Mat2 a {4.0f,5.0f,3.0f,7.0f};
Mat2 b {-1.0f,0.0f,-5.0f,2.0f};
Mat2 c {0.0f,0.0f,0.0f,0.0f};
REQUIRE (a.det() == Approx (13.0f));
REQUIRE (b.det() == Approx(-2.0f));
REQUIRE (c.det() == Approx (0.0f));
}

TEST_CASE ("describe_inverseMat2", "[Det]")
{
Mat2 a {4.0f,5.0f,3.0f,7.0f};
Mat2 b {-1.0f,0.0f,-5.0f,2.0f};
Mat2 c {0.0f,0.0f,0.0f,0.0f};

REQUIRE (inverse(a).e_00 == Approx (0.53846f));
REQUIRE (inverse(a).e_10 == Approx (0.23077f));
REQUIRE (inverse(a).e_01 == Approx (0.38462f));
REQUIRE (inverse(a).e_11 == Approx (0.30769f));
REQUIRE (inverse(c).e_00 == Approx (0.0f));
REQUIRE (inverse(c).e_10 == Approx (0.0f));
REQUIRE (inverse(c).e_01 == Approx (0.0f));
REQUIRE (inverse(c).e_11 == Approx (0.0f));
}

TEST_CASE ("describe_transposeMat2", "[Mat2]")
{
Mat2 a {4.0f,5.0f,3.0f,7.0f};
Mat2 b {-1.0f,0.0f,-5.0f,2.0f};
Mat2 c {0.0f,0.0f,0.0f,0.0f};

REQUIRE (transpose(a).e_00 == Approx (4.0f));
REQUIRE (transpose(a).e_10 == Approx (3.0f));
REQUIRE (transpose(a).e_01 == Approx (5.0f));
REQUIRE (transpose(a).e_11 == Approx (7.0f));
REQUIRE (transpose(c).e_00 == Approx (0.0f));
REQUIRE (transpose(c).e_10 == Approx (0.0f));
REQUIRE (transpose(c).e_01 == Approx (0.0f));
REQUIRE (transpose(c).e_11 == Approx (0.0f));
}

TEST_CASE ("describe_make_rotationMat2", "[Mat2]")
{
REQUIRE (make_rotation_mat2(M_PI).e_00 == Approx (-1.0f));
REQUIRE (make_rotation_mat2(M_PI).e_10 == Approx (0.0f));
REQUIRE (make_rotation_mat2(M_PI).e_01 == Approx (0.0f));
REQUIRE (make_rotation_mat2(M_PI).e_11 == Approx (-1.0f));
REQUIRE (make_rotation_mat2(2*M_PI).e_00 == Approx (1.0f));
REQUIRE (make_rotation_mat2(2*M_PI).e_10 == Approx (0.0f));
REQUIRE (make_rotation_mat2(2*M_PI).e_01 == Approx (0.0f));
REQUIRE (make_rotation_mat2(2*M_PI).e_11 == Approx (1.0f));
REQUIRE (make_rotation_mat2(-M_PI).e_00 == Approx (-1.0f));
REQUIRE (make_rotation_mat2(-M_PI).e_10 == Approx (0.0f));
REQUIRE (make_rotation_mat2(-M_PI).e_01 == Approx (0.0f));
REQUIRE (make_rotation_mat2(-M_PI).e_11 == Approx (-1.0f));
}

TEST_CASE ("describe_color", "[color]")
{
Color a;
REQUIRE (a.r == Approx (0.57f));
REQUIRE (a.g == Approx (0.57f));
REQUIRE (a.b == Approx (0.57f));
}

TEST_CASE ("describe_circumferencecircle", "[circumference]")
{
Circle a {{0.57f, 0.57f, 0.57f}, {0.0f, 0.0f}, 1.0f};
float f1 = a.circumference();
REQUIRE (f1 == Approx(6.28319f));
Circle b {{0.57f, 0.57f, 0.57f}, {0.0f, 0.0f}, 0.0f};
float f2 = b.circumference();
REQUIRE (f2 == Approx(0.0f));
Circle c {{0.57f, 0.57f, 0.57f}, {-4.0f, 4.0f}, 4.0f};
float f3 = c.circumference();
REQUIRE (f3 == Approx(25.13274f));
}

TEST_CASE ("describe_circumferencerectangle", "[circumference]")
{
Rectangle a {{0.57f, 0.57f, 0.57f}, {1.0f, 1.0f}, {2.0f, 2.0f}};
float f1 = a.circumference();
REQUIRE (f1 == Approx(4.0f));
Rectangle b {{0.57f, 0.57f, 0.57f}, {80.0f, 0.0f}, {-17.0f, 4.0f}};
float f2 = b.circumference();
REQUIRE (f2 == Approx(-186.0f));
Rectangle c {{0.57f, 0.57f, 0.57f}, {4.0f, 4.0f}, {4.0f, 5.0f}};
float f3 = c.circumference();
REQUIRE (f3 == Approx(2.0f));
}
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}