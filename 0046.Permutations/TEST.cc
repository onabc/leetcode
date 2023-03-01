#define CATCH_CONFIG_MAIN
#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Permutations", "[permute]")
{
	Solution solution;

	SECTION("one")
	{
		vector<int> nums{ 1,2,3 };
		vector<vector<int>> ans{ {1,2,3},{1,3,2 },{2,1,3},{2,3,1},{3,1,2},{3,2,1} };
		REQUIRE(solution.permute(nums) == ans);
	}

	SECTION("two")
	{
		vector<int> nums{ 0,1 };
		vector<vector<int>> ans{ {0, 1},{1, 0} };
		REQUIRE(solution.permute(nums) == ans);
	}

	SECTION("three")
	{
		vector<int> nums{ 1 };
		vector<vector<int>> ans{ { 1 }, };
		REQUIRE(solution.permute(nums) == ans);
	}
}