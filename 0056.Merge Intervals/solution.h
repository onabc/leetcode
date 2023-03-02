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
//	// �����֤ÿ���ύ�ĺϲ����䶼������ȱ©
//	sort(intervals.begin(), intervals.end());
//	vector<vector<int>> res;
//	// ��ǰ���ϲ�����Ŀ�ʼ�ͽ���
//	int start = intervals[0][0], end = intervals[0][1];
//	for (auto item : intervals) {
//	  // ��ǰ���䲻���ٺϲ��ˣ���Ҫ�ύ
//	  if (item[0] > end) {
//		res.push_back({start, end});
//		start = item[0];
//	  }
//	  end = max(end, item[1]);
//	}
//	// �����һ�������ύ��ȥ
//	res.push_back({start, end});
//	return res;
//  }
};