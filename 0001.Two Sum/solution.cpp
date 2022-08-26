#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

vector<int> twoSum(vector<int>& nums, int target)
{
	unordered_map<int, int> map;
	for (int i = 0, len = nums.size(); i < len; i++)
	{
		auto it = map.find(target - nums[i]);
		if (it != map.end()) {
			return { it->second, i };
		}
		map.emplace(nums[i], i);
	}
	return {};
}