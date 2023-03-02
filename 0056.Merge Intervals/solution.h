using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
	sort(intervals.begin(), intervals.end());
	vector<vector<int>> ans;
	for (int i = 0; i < intervals.size();) {
	  int r = intervals[i][1];
	  int j = i + 1;
	  while (j < intervals.size() && r >= intervals[j][0]) {
		r = max(r, intervals[j][1]);
		++j;
	  }
	  ans.push_back({intervals[i][0], r});
	  i = j;
	}
	return ans;
  }
//  vector<vector<int>> merge(vector<vector<int>> &intervals) {
//	// 排序后保证每次提交的合并区间都不会有缺漏
//	sort(intervals.begin(), intervals.end());
//	vector<vector<int>> res;
//	// 当前待合并区间的开始和结束
//	int start = intervals[0][0], end = intervals[0][1];
//	for (auto item : intervals) {
//	  // 当前区间不能再合并了，需要提交
//	  if (item[0] > end) {
//		res.push_back({start, end});
//		start = item[0];
//	  }
//	  end = max(end, item[1]);
//	}
//	// 把最后一个区间提交上去
//	res.push_back({start, end});
//	return res;
//  }
};