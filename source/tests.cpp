#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"


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

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}