#define CATCH_CONFIG_MAIN
#include "../Catch/catch.hpp"
#include "solution.h"

TEST_CASE("Next Permutation", "[nextPermutation]")
{
	Solution s;
	vector<int> v1{ 1, 2, 3 };
	vector<int> v2{ 3, 2, 1 };
	vector<int> v3{ 1, 1, 5 };
	vector<int> v4{ 1 };
	vector<int> v5{ 1 , 5, 1};
	s.nextPermutation(v1);
	s.nextPermutation(v2);
	s.nextPermutation(v3);
	s.nextPermutation(v4);
	s.nextPermutation(v5);

	REQUIRE(v1 == vector<int>{ 1, 3, 2 });
	REQUIRE(v2 == vector<int>{ 1, 2, 3 });
	REQUIRE(v3 == vector<int>{ 1, 5, 1 });
	REQUIRE(v4 == vector<int>{ 1 });
	REQUIRE(v5 == vector<int>{ 5, 1, 1 });
}