#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  string minWindow(string s, string t) {
	unordered_map<char, int> mps, mpt;
	string ans;
	int cnt = 0;
	for (char c : t) mpt[c]++;
	for (int i = 0, j = 0; i < s.size(); i++) {
	  mps[s[i]]++;
	  if (mps[s[i]] <= mpt[s[i]]) cnt++;
	  while (mps[s[j]] > mpt[s[j]]) mps[s[j++]]--;
	  if (cnt == t.size()) {
		if (ans.empty() || i - j + 1 < ans.size()) {
		  ans = s.substr(j, i - j + 1);
		}
	  }
	}
	return ans;
  }
};