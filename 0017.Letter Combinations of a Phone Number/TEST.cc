#define CATCH_CONFIG_MAIN
#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Letter Combinations of a Phone Number", "[letterCombinations]")
{
	Solution s;
	REQUIRE(s.letterCombinations("23") == vector<string>{"ad", "bd", "cd", "ae", "be", "ce", "af", "bf", "cf"});
	REQUIRE(s.letterCombinations("") == vector<string>{});
}