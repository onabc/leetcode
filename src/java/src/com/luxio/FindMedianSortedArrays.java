package com.luxio;


/**
 * 寻找两个正序数组的中位数
 */
public class FindMedianSortedArrays {
    public static void main(String[] args) {
        int[] nums1 = {2}, nums2 = {};
        double median = findMedianSortedArrays(nums1, nums2);
        System.out.println(median);
    }

    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1.length > nums2.length) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.length, n = nums2.length;
        int left = 0, right = m;
        int median1 = 0, median2 = 0;
        while (left <= right) {
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;
            int num_im = i == 0 ? Integer.MIN_VALUE : nums1[i - 1];
            int num_i = i == m ? Integer.MAX_VALUE : nums1[i];
            int num_jm = j == 0 ? Integer.MIN_VALUE : nums2[j - 1];
            int num_j = j == n ? Integer.MAX_VALUE : nums2[j];
            if (num_im <= num_j) {
                median1 = Math.max(num_im, num_jm);
                median2 = Math.min(num_i, num_j);
                left = i + 1;
            } else {
                right = i - 1;
            }
        }
        return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
    }
}
