#define CATCH_CONFIG_MAIN
#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Trapping Rain Water", "[trap]")
{
	Solution solution;

	SECTION("one")
	{
		vector<int> height{ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
		REQUIRE(solution.trap(height) == 6);
	}
}