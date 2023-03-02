using namespace std;

class Solution {
 public:
  /*
  int maxArea(vector<int>& height) {
	  int ans = 0;

	  int left = 0, right = height.size() - 1;
	  while (left <= right)
	  {
		  int area = min(height[left], height[right]) * (right - left);
		  ans = max(ans, area);
		  if (height[left] < height[right]) {
			  left++;
		  }
		  else {
			  right--;
		  }
	  }

	  return ans;
  }
  */

  /*
  int maxArea(vector<int>& height) {
	  int ans{ 0 };
	  for (auto begin = height.begin(), end = prev(height.end()); begin < end; *begin < *end ? begin++ : end--) {
		  ans = max(ans, static_cast<int>(end - begin) * min(*begin, *end));
	  }
	  return ans;
  }
  */

  int maxArea(vector<int> &height) {
	int left = 0, right = height.size() - 1;
	int ans = 0;
	while (left < right) {
	  ans = height[left] < height[right] ?
			std::max(ans, (right - left) * height[left++]) :
			std::max(ans, (right - left) * height[right--]);
	}
	return ans;
  }
};