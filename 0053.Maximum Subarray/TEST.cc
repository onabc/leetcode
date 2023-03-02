#define CATCH_CONFIG_MAIN

#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Maximum Subarray", "[maxSubArray]")
{
    Solution solution;

    SECTION("one")
    {
        vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
        REQUIRE(solution.maxSubArray(nums) == 6);
    }

    SECTION("two")
    {
        vector<int> nums{5, 4, -1, 7, 8};
        REQUIRE(solution.maxSubArray(nums) == 23);
    }
}