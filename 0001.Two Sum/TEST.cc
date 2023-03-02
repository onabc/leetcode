#define CATCH_CONFIG_MAIN

#include <vector>
#include "../Catch/catch.hpp"
#include "solution.h"

using namespace std;

TEST_CASE("Two Sum", "[twoSum]")
{
  vector<int> nums1{2, 7, 11, 15};
  REQUIRE(twoSum(nums1, 9) == vector<int>{0, 1});

  vector<int> nums2{3, 2, 4};
  REQUIRE(twoSum(nums2, 6) == vector<int>{1, 2});

  vector<int> nums3{3, 3};
  REQUIRE(twoSum(nums3, 6) == vector<int>{0, 1});
}