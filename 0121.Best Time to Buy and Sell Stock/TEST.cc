#define CATCH_CONFIG_MAIN

#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Best Time to Buy and Sell Stock", "[maxProfit]")
{
  Solution solution;

  SECTION("one")
  {
	vector<int> nums{7, 1, 5, 3, 6, 4};
	REQUIRE(solution.maxProfit(nums) == 5);
  }

  SECTION("two")
  {
	vector<int> nums{7, 6, 4, 3, 1};
	REQUIRE(solution.maxProfit(nums) == 0);
  }
}