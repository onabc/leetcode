#define CATCH_CONFIG_MAIN
#include "../Catch/catch.hpp"
#include "solution.h"

using namespace std;

TEST_CASE("Longest Substring Without Repeating Characters", "[lengthOfLongestSubstring]")
{
    REQUIRE(lengthOfLongestSubstring("abcabcbb") == 3);
    REQUIRE(lengthOfLongestSubstring("bbbbb") == 1);
    REQUIRE(lengthOfLongestSubstring("a") == 1);
    REQUIRE(lengthOfLongestSubstring("au") == 2);
    REQUIRE(lengthOfLongestSubstring("bwt") == 3);
    REQUIRE(lengthOfLongestSubstring("abba") == 2);
}