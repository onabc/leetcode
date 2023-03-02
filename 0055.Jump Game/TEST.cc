#define CATCH_CONFIG_MAIN
#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Jump Game", "[canJump]")
{
	Solution solution;

	SECTION("one")
	{
		vector<int> nums{ 2,3,1,1,4 };
		REQUIRE(solution.canJump(nums) == true);
	}

	SECTION("two")
	{
		vector<int> nums{ 3,2,1,0,4 };
		REQUIRE(solution.canJump(nums) == false);
	}
}