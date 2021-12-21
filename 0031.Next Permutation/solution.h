using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() < 2) return;
		auto right = prev(nums.end());
		for (;;) {
			auto last = right--;
			if (*right < *last) {
				auto iter = nums.end();
				while (*right >= *--iter);
				iter_swap(right, iter);
				reverse(last, nums.end());
				return;
			}
			if (right == nums.begin()) {
				reverse(nums.begin(), nums.end());
				return;
			}
		}
	}
};