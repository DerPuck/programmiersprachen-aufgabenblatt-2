#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "Vec2.hpp"


TEST_CASE ("describe_Vec2", "[Vec2]")
{
  Vec2 a = {};
  Vec2 b {5.1f, -9.3f};
REQUIRE (a.x_ == 0.0f);
REQUIRE (a.y_ == 0.0f);
REQUIRE (5.1f == Approx (b.x_));
REQUIRE (-9.3f == Approx (b.y_));
}

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
  a *= 0;
REQUIRE (a.x_ == Approx (0.0f));
REQUIRE (a.y_ == Approx(0.0f));
  b *= 10;
REQUIRE (b.x_ == Approx(51.0f));
REQUIRE (b.y_ == Approx(-93.0f));

}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}