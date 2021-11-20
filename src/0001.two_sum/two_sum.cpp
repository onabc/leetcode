#include <vector>

#include "two_sum.h"
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{
    unordered_map<int, int> map;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        auto it = map.find(target - nums[i]);
        if (it != map.end()) {
            return { it->second, i };
        }
        map[nums[i]] = i;
    }
    return {};
}

/*
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                return { i, j };
            }
        }
    }
    return {};
}
*/
