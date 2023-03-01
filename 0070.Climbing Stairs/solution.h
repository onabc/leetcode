using namespace std;

class Solution {
public:
	/*int climbStairs(int n) {
		int ans = 0;
		vector<int> dp(n + 1, 0);
		dp[1] = 1, dp[2] = 2;
		for (int i = 3; i <= n; ++i) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}

		return dp[n];
	}*/

	int climbStairs(int n) {
		int n1 = 0, n2 = 1, tmp;
		for (int i = 1; i <= n; ++i) {
			tmp = n2;
			n2 += n1;
			n1 = tmp;
		}
		return n2;
	}
};