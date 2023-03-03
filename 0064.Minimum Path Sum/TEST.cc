#define CATCH_CONFIG_MAIN

#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Unique Paths", "[uniquePaths]")
{
  Solution solution;

  SECTION("one")
  {
	vector<vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
	REQUIRE(solution.minPathSum(grid) == 7);
  }

  SECTION("two")
  {
	vector<vector<int>> grid{{1, 2, 3}, {4, 5, 6}};
	REQUIRE(solution.minPathSum(grid) == 12);
  }
}