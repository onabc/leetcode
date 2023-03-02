#include <string>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
  int ans = 0;
  unordered_map<char, int> map;
  for (int i = 0, j = 0, len = s.length(); j < len; j++) {
	char c = s.at(j);
	if (map.count(c)) {
	  i = max(map.at(c), i);
	}
	ans = max(ans, j - i + 1);
	map[c] = j + 1;    //下标 + 1 代表 i 要移动的下个位置
  }
  return ans;
}