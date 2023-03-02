#define CATCH_CONFIG_MAIN

#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("3Sum", "[threeSum]")
{
    Solution s;
    SECTION("common")
    {
        REQUIRE(s.threeSum(vector<int>{-1, 0, 1, 2, -1, -4}) == vector<vector<int>>{{-1, -1, 2},
                                                                                    {-1, 0,  1}});
        REQUIRE(s.threeSum(vector<int>{1, 1, 1, 0}) == vector<vector<int>>{});
        REQUIRE(s.threeSum(vector<int>{0, 0, 0}) == vector<vector<int>>{{0, 0, 0}});
    }
}