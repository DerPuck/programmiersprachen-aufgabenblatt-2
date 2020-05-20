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
}
TEST_CASE ("describe_-Vec2", "[Vec2]")
{
  Vec2 a = {};
  Vec2 b {5.1f, -9.3f};
  a -= b;
REQUIRE (a.x_ == Approx (-5.1f));
REQUIRE (a.y_ == Approx(9.3f));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}