#define CATCH_CONFIG_MAIN

#include "../Catch/catch.hpp"
#include "solution.h"

using namespace std;

TEST_CASE("Median of Two Sorted Arrays", "[findMedianSortedArrays]")
{
    REQUIRE(findMedianSortedArrays(vector<int>{1, 3}, vector<int>{2}) == 2);
    REQUIRE(findMedianSortedArrays(vector<int>{1, 2}, vector<int>{3, 4}) == 2.5);
    REQUIRE(findMedianSortedArrays(vector<int>{0, 0}, vector<int>{0, 0}) == 0);
    REQUIRE(findMedianSortedArrays(vector<int>{}, vector<int>{1}) == 1);
    REQUIRE(findMedianSortedArrays(vector<int>{2}, vector<int>{}) == 2);
}