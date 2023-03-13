#define CATCH_CONFIG_MAIN

#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Subsets", "[subsets]")
{
  Solution solution;

  SECTION("one")
  {
	vector<int> nums{1, 2, 3};
	vector<vector<int>> ans{{}, {1}, {1, 2}, {1, 2, 3}, {1, 3}, {2}, {2, 3}, {3}};
	REQUIRE(solution.subsets(nums) == ans);
  }

  SECTION("two")
  {
	vector<int> nums{0};
	vector<vector<int>> ans{{}, {0}};
	REQUIRE(solution.subsets(nums) == ans);
  }
}