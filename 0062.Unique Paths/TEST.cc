#define CATCH_CONFIG_MAIN

#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Unique Paths", "[uniquePaths]")
{
  Solution solution;

  SECTION("one")
  {
	REQUIRE(solution.uniquePaths(3, 7) == 28);
  }

  SECTION("two")
  {
	REQUIRE(solution.uniquePaths(3, 2) == 3);
  }
}