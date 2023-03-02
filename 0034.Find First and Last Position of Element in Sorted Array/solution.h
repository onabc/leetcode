using namespace std;

class Solution {
 public:
  /// <summary>
  /// 先找大于等于target的第一个，再找大于target的第一个
  /// </summary>
  /// <param name="nums"></param>
  /// <param name="target"></param>
  /// <returns></returns>
  vector<int> searchRange(vector<int> &nums, int target) {
	int l = search(nums, target);
	int r = search(nums, target + 1);
	if (l == nums.size() || nums[l] != target)
	  return {-1, -1};
	return {l, r - 1};
  }

  /// <summary>
  /// 找大于等于target的第一个
  /// </summary>
  int search(vector<int> &nums, int target) {
	int l = 0, r = nums.size();
	while (l < r) {
	  int mid = (l + r) >> 1;
	  if (nums[mid] >= target) {
		r = mid;
	  } else {
		l = mid + 1;
	  }
	}
	return l;
  }
};