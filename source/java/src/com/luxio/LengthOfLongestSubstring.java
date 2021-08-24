package com.luxio;

import java.util.HashMap;
import java.util.Map;

/**
 * 无重复字符的最长子串
 */
public class LengthOfLongestSubstring {
    public static void main(String[] args) {
        String s = "abcabcbb";
        int len = lengthOfLongestSubstring(s);
        System.out.println(len);
    }

    public static int lengthOfLongestSubstring(String s) {
        int ans = 0;
        int n = s.length();
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0, j = 0; j < n; j++) {
            if (map.containsKey(s.charAt(j))) {
                i = Math.max(map.get(s.charAt(j)), i);
            }
            ans = Math.max(ans, j - i + 1);
            map.put(s.charAt(j), j + 1);
        }
        return ans;
    }
}
