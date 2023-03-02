using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
	int len = s.size();
	if (len == 0) return s;
	int start = 0, end = 0;
	for (int i = 0; i < len; i++) {
	  expandArroundCenter(s, i, i, start, end);
	  expandArroundCenter(s, i, i + 1, start, end);
	}
	return s.substr(start, end - start + 1);
  }

 private:
  static void expandArroundCenter(const string &s, int left, int right, int &start, int &end) {
	while (left >= 0 && right < s.size() && s.at(left) == s.at(right))
	  --left, ++right;
	++left, --right;
	if (right - left > end - start) {
	  start = left;
	  end = right;
	}
  }
};
