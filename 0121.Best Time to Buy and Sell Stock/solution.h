#include<climits>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
	int maxProfit = 0, minPrice = INT_MAX;
	for (int price : prices) {
	  maxProfit = std::max(maxProfit, price - minPrice);
	  minPrice = std::min(minPrice, price);
	}
	return maxProfit;
  }
};