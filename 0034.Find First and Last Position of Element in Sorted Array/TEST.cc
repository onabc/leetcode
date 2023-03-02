#define CATCH_CONFIG_MAIN

#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Search in Rotated Sorted Array", "[search]")
{
    Solution s;
    SECTION("common")
    {
        vector<int> arr{5, 7, 7, 8, 8, 10};
        REQUIRE(s.searchRange(arr, 8) == vector<int>{3, 4});
    }

    SECTION("no")
    {
        vector<int> arr{1};
        REQUIRE(s.searchRange(arr, 0) == vector<int>{-1, -1});
    }

    SECTION("all")
    {
        vector<int> arr{2, 2};
        REQUIRE(s.searchRange(arr, 2) == vector<int>{0, 1});
    }
}