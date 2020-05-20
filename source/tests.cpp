#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "Vec2.hpp"


TEST_CASE ("describe_Vec2", "[Vec2]")
{
  Vec2 a = {};
  Vec2 b {5.1f, -9.3f};
REQUIRE (a.x == 0.0f);
REQUIRE (a.y == 0.0f);
REQUIRE (5.1f == Approx (b.x));
REQUIRE (-9.3f == Approx (b.y));
}



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}