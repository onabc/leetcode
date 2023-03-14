#define CATCH_CONFIG_MAIN

#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Single Number", "[singleNumber]")
{
  Solution solution;

  SECTION("one")
  {
	vector<int> nums{2, 2, 1};
	REQUIRE(solution.singleNumber(nums) == 1);
  }

  SECTION("two")
  {
	vector<int> nums{4, 1, 2, 1, 2};
	REQUIRE(solution.singleNumber(nums) == 4);
  }
}