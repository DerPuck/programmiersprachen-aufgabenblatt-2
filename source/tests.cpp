#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "Vec2.hpp"


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
TEST_CASE ("describe_freefunction/Vec2", "[Vec2]")
{
  Vec2 a = {};
  Vec2 b {5.1f, -9.3f};
  Vec2 n1 = a + b;
REQUIRE (n1.x_ == Approx(5.1f));
REQUIRE (n1.y_ == Approx(-9.3f));
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}