using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		int n = nums.size();
		if (n < 3) return ans;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n; i++)
		{
			if (i && nums[i] == nums[i - 1]) continue;
			int b = i + 1, e = n - 1;
			while (b < e) {
				if (nums[b] + nums[e] + nums[i] > 0)
					--e;
				else if (nums[b] + nums[e] + nums[i] < 0)
					++b;
				else {
					ans.push_back({ nums[i], nums[b], nums[e] });
					++b, --e;
					//ÅÅ³ýÖØ¸´µÄ½â
					while (b < e && nums[b] == nums[b - 1]) b++;
					while (b < e && nums[e] == nums[e + 1]) e--;
				}
			}
		}
		return ans;
	}
	/*
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		int len = nums.size();
		if (len < 3) return ans;
		sort(nums.begin(), nums.end());
		for (int first = 0; first < len; ++first)
		{
			if (first && nums[first] == nums[first - 1]) {
				continue;
			}
			int third = len - 1;
			int target = -nums[first];
			for (int second = first + 1; second < len - 1; ++second)
			{
				if (second > first + 1 && nums[second] == nums[second - 1]) {
					continue;
				}

				while (third > second && nums[second] + nums[third] > target) {
					--third;
				}
				if (second == third) {
					break;
				}
				if (nums[second] + nums[third] == target) {
					ans.push_back({ nums[first], nums[second], nums[third] });
				}
			}
		}
		return ans;
	}
	*/
};