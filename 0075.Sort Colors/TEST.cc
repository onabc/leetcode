#define CATCH_CONFIG_MAIN

#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Sort Colors", "[sortColors]")
{
  Solution solution;

  SECTION("one")
  {
	vector<int> nums{2, 0, 2, 1, 1, 0};
	vector<int> ans{0, 0, 1, 1, 2, 2};
	solution.sortColors(nums);
	REQUIRE(nums == ans);
  }

  SECTION("two")
  {
  }
}