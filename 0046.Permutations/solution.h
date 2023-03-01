using namespace std;

class Solution {
	/*
	* 回溯算法
	*/
private:
	vector<vector<int>> ans;
	vector<int> path;
	void backtrack(vector<int>& nums, int len, vector<bool>& used) {
		if (path.size() == len) {
			ans.push_back(path);
			return;
		}
		for (int i = 0; i < len; ++i) {
			if (used[i]) continue;
			path.push_back(nums[i]);
			used[i] = true;
			backtrack(nums, len, used);
			path.pop_back();
			used[i] = false;
		}
	}
public:
	vector<vector<int>> permute(vector<int>& nums) {
		int len = nums.size();
		if (len < 2) return { nums };
		vector<bool> used(len, false);
		backtrack(nums, len, used);
		return ans;
	}

	/*
	* 交换法
	*/
	//private:
	//	void upset(vector<int>& nums, int begin, vector<vector<int>>& ans) {
	//		if (begin == nums.size()) {
	//			vector<int> tmp(nums);
	//			ans.push_back(tmp);
	//			return;
	//		}
	//		for (int i = begin; i < nums.size(); ++i) {
	//			std::swap(nums[begin], nums[i]);
	//			upset(nums, begin + 1, ans);
	//			std::swap(nums[begin], nums[i]);
	//		}
	//	}
	//public:
	//	vector<vector<int>> permute(vector<int>& nums) {
	//		vector<vector<int>> ans;
	//		upset(nums, 0, ans);
	//		return ans;
	//	}
};