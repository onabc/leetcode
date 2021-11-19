#include <iostream>
#include <vector>

#include "two_sum.h"

using namespace std;

int main()
{
	vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;

	bool success = vector<int>{0, 1}  == twoSum(nums, 9);

	cout<< success << endl;

	system("pause");
	return 0;
}