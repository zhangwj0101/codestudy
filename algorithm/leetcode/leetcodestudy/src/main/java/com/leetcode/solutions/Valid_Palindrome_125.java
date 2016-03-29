package com.leetcode.solutions;

import org.junit.Test;

/**
 * Created by zwj on 2016/3/13.
 */
public class Valid_Palindrome_125 {
    /**
     * 常规解法
     *
     * @param s
     * @return
     */
    public boolean isPalindrome(String s) {
        StringBuilder res = new StringBuilder();
        for (char t : s.toLowerCase().toCharArray()) {
            if ((t >= '0' && t <= '9') || (t >= 'a' && t <= 'z')) {
                res.append(t);
            }
        }
        return res.toString().equals(res.reverse().toString());

    }

    /**
     * 左右指针
     *
     * @param s
     * @return
     */
    public boolean isPalindromeP(String s) {
        if (s == null) {
            return false;
        }
        int len = s.length();
        int left = 0;
        int right = len - 1;
        s = s.toLowerCase();
        while (left < right) {
            if (!Character.isLetterOrDigit(s.charAt(left))) {
                left++;
            } else if (!Character.isLetterOrDigit(s.charAt(right))) {
                right--;
            } else if (s.charAt(left) != s.charAt(right)) {
                return false;
            } else {
                left++;
                right--;
            }
        }
        return true;

    }

    @Test
    public void tes() {
        String s = "0p";
        System.out.println(isPalindrome(s));
    }
}
