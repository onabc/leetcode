#include <vector>
#include<climits>
#include "solution.h"

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
  int len1 = nums1.size(), len2 = nums2.size();
  if (len1 > len2) return findMedianSortedArrays(nums2, nums1);

  int left = 0, right = len1;
  int median1 = 0, median2 = 0;

  while (left <= right) {
	int i = (left + right) / 2;
	int j = (len1 + len2 + 1) / 2 - i;

	int nums1_left_max = i == 0 ? INT_MIN : nums1[i - 1];
	int nums1_right_min = i == len1 ? INT_MAX : nums1[i];

	int nums2_left_max = j == 0 ? INT_MIN : nums2[j - 1];
	int nums2_right_min = j == len2 ? INT_MAX : nums2[j];

	if (nums1_left_max <= nums2_right_min) {
	  median1 = max(nums1_left_max, nums2_left_max);
	  median2 = min(nums1_right_min, nums2_right_min);
	  left = i + 1;
	} else {
	  right = i - 1;
	}
  }
  return (len1 + len2) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
}