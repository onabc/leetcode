#include <array>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (!digits.size()) return ans;
        ans.push_back("");
        array<string, 10> arr{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (auto digit: digits) {
            vector<string> tmp;
            for (auto c: arr[digit - '0']) {
                for (auto prev: ans) {
                    tmp.push_back(prev + c);
                }
            }
            ans = tmp;
        }
        return ans;
    }
};