#define CATCH_CONFIG_MAIN

#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Longest Valid Parentheses", "[longestValidParentheses]")
{
    Solution s;

    REQUIRE(s.longestValidParentheses("(()") == 2);
    REQUIRE(s.longestValidParentheses(")()())") == 4);
    REQUIRE(s.longestValidParentheses("") == 0);
}