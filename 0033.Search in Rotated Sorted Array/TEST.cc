#define CATCH_CONFIG_MAIN

#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Search in Rotated Sorted Array", "[search]")
{
  SECTION("common")
  {
	vector<int> arr{0, 1, 2, 4, 5, 6, 7};
	Solution s;
	REQUIRE(s.search(arr, 2) == 2);
  }

  SECTION("rotated")
  {
	vector<int> arr{4, 5, 6, 7, 0, 1, 2};
	Solution s;
	REQUIRE(s.search(arr, 3) == -1);
  }

  SECTION("extreme case")
  {
	vector<int> arr{3, 1};
	Solution s;
	REQUIRE(s.search(arr, 1) == 1);
  }
}