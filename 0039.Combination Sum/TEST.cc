#define CATCH_CONFIG_MAIN
#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Combination Sum", "[combinationSum]")
{
	Solution solution;

	SECTION("one")
	{
		vector<int> candidates{ 2,3,6,7 };
		int target{ 7 };
		vector<vector<int>> ans{ {2, 2, 3},{7} };
		REQUIRE(solution.combinationSum(candidates, 7) == ans);
	}
}