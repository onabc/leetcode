#define CATCH_CONFIG_MAIN

#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("3Sum", "[threeSum]")
{
  Solution s;
  SECTION("one")
  {
	vector<int> nums{-1, 0, 1, 2, -1, -4};
	REQUIRE(s.threeSum(nums) == vector<vector<int>>{{-1, -1, 2},
													{-1, 0, 1}});
  }

  SECTION("two")
  {
	vector<int> nums{};
	REQUIRE(s.threeSum(nums) == vector<vector<int>>{});
  }

  SECTION("three")
  {
	vector<int> nums{0, 0, 0};
	REQUIRE(s.threeSum(nums) == vector<vector<int>>{{0, 0, 0}});
  }
}