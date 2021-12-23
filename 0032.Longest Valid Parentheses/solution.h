#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> cache;
        cache.push(-1);
        for (int i = 0; i < s.size(); i++)
        {
            if (s.at(i) == '(') {
                cache.push(i);
            }
            else {
                cache.pop();
                if (cache.empty()) {
                    cache.push(i);
                }
                else {
                    ans = max(ans, i - cache.top());
                }
            }
        }

        return ans;
    }
};