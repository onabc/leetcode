using namespace std;

class Solution {
public:
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
    }
};