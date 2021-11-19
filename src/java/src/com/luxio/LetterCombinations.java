package com.luxio;

import java.util.*;

public class LetterCombinations {
    public static void main(String[] args) {
        String digits = "23";
        System.out.println(letterCombinations1(digits));
        System.out.println(letterCombinations2(digits));
    }

    public static List<String> letterCombinations1(String digits) {
        List<String> combinations = new ArrayList<>();
        if(digits.isEmpty()) return combinations;
        Map<Character, String> phoneMap = new HashMap<Character, String>() {{
            put('2', "abc");
            put('3', "def");
            put('4', "ghi");
            put('5', "jkl");
            put('6', "mno");
            put('7', "pqrs");
            put('8', "tuv");
            put('9', "wxyz");
        }};
        backtrack(combinations, phoneMap, digits, 0, new StringBuffer());
        return combinations;
    }

    public static void backtrack(List<String> combinations, Map<Character, String> phoneMap, String digits, int index, StringBuffer combination){
        if(index == digits.length()) {
            combinations.add(combination.toString());
        } else {
            char digit = digits.charAt(index);
            String letters = phoneMap.get(digit);
            for(int i = 0; i < letters.length(); i ++) {
                combination.append(letters.charAt(i));
                backtrack(combinations, phoneMap, digits, index + 1, combination);
                combination.deleteCharAt(index);
            }
        }
    }

    /**
     * 队列的方式
     * @param digits
     * @return
     */
    public static List<String> letterCombinations2(String digits) {
        LinkedList<String> ans = new LinkedList<>();

        if (digits.isEmpty()) return ans;

        String[] mapping = new String[]{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        ans.add("");
        for (int i = 0; i < digits.length(); i++) {
            int x = Character.getNumericValue(digits.charAt(i));
            while (ans.peek().length() == i) {
                String t = ans.remove();
                for(char c : mapping[x].toCharArray()) {
                    ans.add(t + c);
                }
            }
        }

        return ans;
    }
}
