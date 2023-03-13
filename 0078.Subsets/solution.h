using namespace std;

class Solution {
 private:
  vector<int> path;
  vector<vector<int>> ans;
  void backtrack(vector<int> &nums, int start) {
	ans.push_back(path);
	for (int i = start; i < nums.size(); i++) {
	  path.push_back(nums[i]);
	  backtrack(nums, i + 1);
	  path.pop_back();
	}
  }
 public:
  vector<vector<int>> subsets(vector<int> &nums) {
	backtrack(nums, 0);
	return ans;
  }
};