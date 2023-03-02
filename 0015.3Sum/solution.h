using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> &nums) {
	vector<vector<int>> ans;
	int len = nums.size();
	if (len < 3) return ans;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < len; ++i) {
	  if (i && nums[i] == nums[i - 1]) continue;
	  int begin = i + 1, end = len - 1;
	  while (begin < end) {
		int sum = nums[i] + nums[begin] + nums[end];
		if (sum > 0) --end;
		else if (sum < 0) ++begin;
		else {
		  ans.push_back({nums[i], nums[begin], nums[end]});
		  ++begin, --end;
		  while (begin < end && nums[begin] == nums[begin - 1]) ++begin;
		  while (begin < end && nums[end] == nums[end + 1]) --end;
		}
	  }
	}

	return ans;
  }
  /*
  vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> ans;
      int len = nums.size();
      if (len < 3) return ans;
      sort(nums.begin(), nums.end());
      for (int first = 0; first < len; ++first)
      {
          if (first && nums[first] == nums[first - 1]) {
              continue;
          }
          int third = len - 1;
          int target = -nums[first];
          for (int second = first + 1; second < len - 1; ++second)
          {
              if (second > first + 1 && nums[second] == nums[second - 1]) {
                  continue;
              }

              while (third > second && nums[second] + nums[third] > target) {
                  --third;
              }
              if (second == third) {
                  break;
              }
              if (nums[second] + nums[third] == target) {
                  ans.push_back({ nums[first], nums[second], nums[third] });
              }
          }
      }
      return ans;
  }
  */
};