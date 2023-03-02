#define CATCH_CONFIG_MAIN

#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Group Anagrams", "[groupAnagrams]")
{
  Solution solution;

  SECTION("one")
  {
	vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> ans{{"eat", "tea", "ate"},
							   {"tan", "nat"},
							   {"bat"}};
	REQUIRE(solution.groupAnagrams(strs) == ans);
  }

  SECTION("two")
  {
	vector<string> strs{""};
	vector<vector<string>> ans{{""}};
	REQUIRE(solution.groupAnagrams(strs) == ans);
  }

  SECTION("three")
  {
	vector<string> strs{"a"};
	vector<vector<string>> ans{{"a"}};
	REQUIRE(solution.groupAnagrams(strs) == ans);
  }
}