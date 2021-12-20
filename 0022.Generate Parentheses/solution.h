#include <string>

using namespace std;

class Solution {
	vector<string> ans;
public:
	vector<string> generateParenthesis(int n) {
		generate("", n, 0);
		return ans;
	}

	void generate(string str, int l, int r) {
		if (l == 0 && r == 0) ans.push_back(str);
		if (l > 0) generate(str + "(", l - 1, r + 1);
		if (r > 0) generate(str + ")", l, r - 1);
	}
};