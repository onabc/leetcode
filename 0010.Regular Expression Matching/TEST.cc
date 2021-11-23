#define CATCH_CONFIG_MAIN
#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Regular Expression Matching", "[isMatch]")
{
	Solution s;
	REQUIRE_FALSE(s.isMatch("mississippi", "mis*is*p*."));
	REQUIRE(s.isMatch("aab", "c*a*b"));
	REQUIRE_FALSE(s.isMatch("aa", "a"));
	REQUIRE(s.isMatch("aa", "a*"));
	REQUIRE(s.isMatch("aaa", "ab*a*c*a"));
}