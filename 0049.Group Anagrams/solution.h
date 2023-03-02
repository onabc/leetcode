#include <unordered_map>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
	vector<vector<string>> ans{};
	unordered_map<string, vector<string>> map;
	for (string str : strs) {
	  string data = str;
	  sort(str.begin(), str.end());
	  map[str].push_back(data);
	}
	for (auto pair : map) {
	  ans.push_back(pair.second);
	}

	return ans;
  }
};