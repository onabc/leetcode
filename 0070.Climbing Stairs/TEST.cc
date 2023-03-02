#define CATCH_CONFIG_MAIN

#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Climbing Stairs", "[climbStairs]")
{
  Solution solution;

  SECTION("one")
  {
	REQUIRE(solution.climbStairs(2) == 2);
  }

  SECTION("two")
  {
	REQUIRE(solution.climbStairs(3) == 3);
  }
}