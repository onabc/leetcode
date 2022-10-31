using namespace std;

class Solution {
private:
	void dfs(vector<int>& candidates, int begin, int len, int target, vector<int>& path, vector<vector<int>>& res) {
		if (target == 0) {
			res.push_back(path);
			return;
		}
		for (int i = begin; i < len; i++) {
			if (target - candidates[i] < 0) {
				break;
			}
			path.push_back(candidates[i]);
			dfs(candidates, i, len, target - candidates[i], path, res);
			path.pop_back();
		}
	}
public:
	/// <summary>
	/// 回溯算法 + 剪枝
	/// </summary>
	/// <param name="candidates"></param>
	/// <param name="target"></param>
	/// <returns></returns>
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		int len = candidates.size();
		if (len == 0) {
			return res;
		}
		sort(candidates.begin(), candidates.end());
		vector<int> path;
		dfs(candidates, 0, len, target, path, res);
		return res;
	}
	/* 动态路径法
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<vector<int>>> dp(target + 1);
		for (auto &d : candidates) {
			for (int i = d; i <= target; i++) {
				auto& cur = dp[i];
				if (i == d) {
					cur.push_back({d});
				}
				else {
					auto &pre = dp[i - d];
					for (auto v : pre) {
						v.push_back(d);
						cur.push_back(v);
					}
				}
			}
		}
		return dp[target];
	}*/
};