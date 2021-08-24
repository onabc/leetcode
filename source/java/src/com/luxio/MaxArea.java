package com.luxio;

public class MaxArea {
    public static void main(String[] args) {
        int[] height = {4, 3, 2, 1, 4};
        System.out.println(maxArea(height));
    }

    public static int maxArea(int[] height) {
        int left = 0, right = height.length - 1;
        int ans = 0;
        while (left < right) {
            int area = Math.max(height[left], height[right]) * (right - left);
            ans = Math.max(area, ans);
            if (height[left] <= height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return ans;
    }
}
