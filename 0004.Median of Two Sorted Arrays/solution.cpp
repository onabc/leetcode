#include <vector>
#include "solution.h"

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	if (nums1.size() > nums2.size()) {
		return findMedianSortedArrays(nums2, nums1);
	}

	int m = nums1.size();
	int n = nums2.size();

	int left = 0, right = m;

	// median1：前一部分的最大值
	// median2：后一部分的最小值
	int median1 = 0, median2 = 0;

	while (left <= right)
	{
		int i = (left + right) / 2;
		int j = (m + n + 1) / 2 - i;

		int num_im = i == 0 ? INT_MIN : nums1[i - 1];
		int num_i = i == m ? INT_MAX : nums1[i];
		int num_jm = j == 0 ? INT_MIN : nums2[j - 1];
		int num_j = j == n ? INT_MAX : nums2[j];

		if (num_im <= num_j) {
			median1 = max(num_im, num_jm);
			median2 = min(num_i, num_j);
			left = i + 1;
		}
		else {
			right = i - 1;
		}
	}

	return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
}