#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
	stack<char> stk;
	unordered_map<char, char> map = {
		{')', '('},
		{']', '['},
		{'}', '{'},
	};
	for (char c : s) {
	  if (map.count(c)) {
		if (stk.empty() || map[c] != stk.top()) return false;
		stk.pop();
	  } else {
		stk.push(c);
	  }
	}
	return stk.empty();
  }
};