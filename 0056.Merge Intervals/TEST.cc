#define CATCH_CONFIG_MAIN

#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Merge Intervals", "[merge]")
{
  Solution solution;

  SECTION("one")
  {
	vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
	vector<vector<int>> ans{{1, 6}, {8, 10}, {15, 18}};
	REQUIRE(solution.merge(intervals) == ans);
  }

  SECTION("two")
  {
  }
}