#define CATCH_CONFIG_MAIN
#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Container With Most Water", "[maxArea]")
{
	vector<int> nums{ 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	Solution s;
	REQUIRE(s.maxArea(nums) == 49);
}