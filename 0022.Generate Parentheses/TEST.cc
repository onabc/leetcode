#define CATCH_CONFIG_MAIN

#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Generate Parentheses", "[generateParenthesis]")
{
  Solution s;
  auto ans = s.generateParenthesis(3);
  REQUIRE((ans == vector<string>{"((()))", "(()())", "(())()", "()(())", "()()()"}));
}