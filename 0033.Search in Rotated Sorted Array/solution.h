using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (nums[mid] == target) return mid;
			if ((nums[l] <= target && target < nums[mid]) || (nums[mid] < nums[l] && (target < nums[mid] || target >= nums[l])))
				r = mid - 1;
			else if ((nums[mid] < target && target <= nums[r]) || (nums[r] < nums[mid] && (target > nums[mid] || target <= nums[r])))
				l = mid + 1;
			else break;
		}
		return -1;
	}
};