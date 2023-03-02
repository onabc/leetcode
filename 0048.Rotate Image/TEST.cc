#define CATCH_CONFIG_MAIN

#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Rotate Image", "[rotate]")
{
  Solution solution;

  SECTION("one")
  {
	vector<vector<int>> matrix{{1, 2, 3},
							   {4, 5, 6},
							   {7, 8, 9}};
	vector<vector<int>> ans{{7, 4, 1},
							{8, 5, 2},
							{9, 6, 3}};
	solution.rotate(matrix);
	REQUIRE(matrix == ans);
  }

  SECTION("two")
  {
	vector<vector<int>> matrix{{5, 1, 9, 11},
							   {2, 4, 8, 10},
							   {13, 3, 6, 7},
							   {15, 14, 12, 16}};
	vector<vector<int>> ans{{15, 13, 2, 5},
							{14, 3, 4, 1},
							{12, 6, 8, 9},
							{16, 7, 10, 11}};
	solution.rotate(matrix);
	REQUIRE(matrix == ans);
  }
}