#define CATCH_CONFIG_MAIN

#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Edit Distance", "[minDistance]")
{
  Solution solution;

  SECTION("one")
  {
	string word1 = "horse", word2 = "ros";
	REQUIRE(solution.minDistance(word1, word2) == 3);
  }

  SECTION("two")
  {
	string word1 = "intention", word2 = "execution";
	REQUIRE(solution.minDistance(word1, word2) == 5);
  }
}