#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
	int ans = 0;
	unordered_map<char, int> map;
	for (int i = 0, j = 0; j < s.length(); j++)
	{
		auto it = map.find(s.at(j));
		if (it != map.end()) {
			i = max(it->second, i);
		}
		ans = max(ans, j - i + 1);
		map[s.at(j)] = j + 1;	//�±� + 1 ���� i Ҫ�ƶ����¸�λ��
	}
	return ans;
}