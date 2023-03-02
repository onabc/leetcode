using namespace std;

class Solution {
public:
    /*
    * ¶¯Ì¬¹æ»®
    */
    int trap(vector<int> &height) {
        int sum = 0;
        int len = height.size();
        if (len <= 2) return sum;

        int max_left = 0;
        vector<int> max_right(len, 0);
        for (int i = len - 2; i >= 0; --i) {
            max_right[i] = max(max_right[i + 1], height[i + 1]);
        }
        for (int i = 1; i < len - 1; ++i) {
            max_left = std::max(max_left, height[i - 1]);
            int min = std::min(max_left, max_right[i]);
            if (min > height[i]) sum += (min - height[i]);
        }

        return sum;
    }
};