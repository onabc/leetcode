using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
	vector<vector<int>> ans;
	// 排序后保证每次提交的合并区间都不会有缺漏
	sort(intervals.begin(), intervals.end());
	// 当前待合并区间的开始和结束
	int start = intervals[0][0], end = intervals[0][1];
	for (auto item : intervals) {
	  if (item[0] > end) {
		ans.push_back({start, end});
		start = item[0];
	  }
	  end = max(end, item[1]);
	}
	// 把最后一个区间提交上去
	ans.push_back({start, end});
	return ans;
  }
};