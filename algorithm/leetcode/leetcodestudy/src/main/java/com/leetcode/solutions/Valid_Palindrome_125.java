package com.leetcode.solutions;

import org.junit.Test;

/**
 * Created by zwj on 2016/3/13.
 */
public class Valid_Palindrome_125 {
    public boolean isPalindrome(String s) {
        StringBuilder res = new StringBuilder();
        for (char t : s.toLowerCase().toCharArray()) {
            if ((t >= 48 && t <= 57) || (t >= 'a' && t <= 'z')) {
                res.append(t);
            }
        }
        return res.toString().equals(res.reverse().toString());

    }

    @Test
    public void tes() {
        String s = "0p";

        System.out.println(isPalindrome(s));
    }
}
