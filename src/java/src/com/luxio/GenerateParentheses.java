package com.luxio;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class GenerateParentheses {
    public static void main(String[] args) {
        List<String> str1 = generateParenthesis(4);
        System.out.println(str1);
    }

    public static List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        if (n == 0) {
            ans.add("");
        } else {
            for (int i = 0; i < n; i++) {
                for (String left : generateParenthesis(i)) {
                    for (String right : generateParenthesis(n - i - 1)) {
                        ans.add("(" + left + ")" + right);
                    }
                }
            }
        }
        return ans;
    }
}
