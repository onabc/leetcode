#include <string>

using namespace std;

class Solution {
 public:
  void sortColors(vector<int> &nums) {
	if (nums.size() < 2) return;
	int n0 = 0, n2 = nums.size() - 1;
	int i = 0;
	while (i <= n2) {
	  if (nums[i] == 0) {
		swap(nums[i], nums[n0]);
		++n0;
		++i;
	  } else if (nums[i] == 1) {
		++i;
	  } else if (nums[i] == 2) {
		swap(nums[i], nums[n2]);
		--n2;
	  }
	}
  }
//  void sortColors(vector<int> &nums) {
//	int n0 = 0, n1 = 0;
//	for (int i = 0; i < nums.size(); i++) {
//	  int num = nums[i];
//	  nums[i] = 2;
//	  if (num < 2) {
//		nums[n1++] = 1;
//	  }
//	  if (num < 1) {
//		nums[n0++] = 0;
//	  }
//	}
//  }
};