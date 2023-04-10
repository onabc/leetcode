#define CATCH_CONFIG_MAIN

#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Minimum Window Substring", "[minWindow")
{
  Solution solution;

  SECTION("one")
  {
	string s = "ADOBECODEBANC";
	string t = "ABC";
	REQUIRE(solution.minWindow(s, t) == "BANC");
  }

  SECTION("two")
  {
	string s = "a";
	string t = "aa";
	REQUIRE(solution.minWindow(s, t) == "");
  }

  SECTION("three")
  {
	string s = "a";
	string t = "a";
	REQUIRE(solution.minWindow(s, t) == "a");
  }
}