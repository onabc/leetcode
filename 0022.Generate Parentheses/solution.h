#include <string>

using namespace std;

class Solution {
	vector<string> ans;
public:
	vector<string> generateParenthesis(int n) {
		generate("", n, 0);
		return ans;
	}

	void generate(string str, int n, int m) {
		if (n == 0 && m == 0) ans.push_back(str);
		if (n > 0) generate(str + "(", n - 1, m + 1);
		if (m > 0) generate(str + ")", n, m - 1);
	}
};