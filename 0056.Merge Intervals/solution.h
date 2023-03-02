using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
	vector<vector<int>> ans;
	// �����֤ÿ���ύ�ĺϲ����䶼������ȱ©
	sort(intervals.begin(), intervals.end());
	// ��ǰ���ϲ�����Ŀ�ʼ�ͽ���
	int start = intervals[0][0], end = intervals[0][1];
	for (auto item : intervals) {
	  if (item[0] > end) {
		ans.push_back({start, end});
		start = item[0];
	  }
	  end = max(end, item[1]);
	}
	// �����һ�������ύ��ȥ
	ans.push_back({start, end});
	return ans;
  }
};