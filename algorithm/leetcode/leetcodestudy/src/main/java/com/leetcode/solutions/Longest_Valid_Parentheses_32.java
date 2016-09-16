/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import java.util.Stack;

/**
 * @author zhangwj
 */
public class Longest_Valid_Parentheses_32 {

    public static void main(String[] args) {
        String s = ")()()";
        System.out.println(longestValidParentheses(s));
    }


    public static int longestValidParentheses(String s) {
        int[] dp = new int[s.length()];
        int max = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i > 0 && s.charAt(i) == ')') {
                int pre = i - dp[i - 1] - 1;
                if (pre >= 0 && s.charAt(pre) == '(') {
                    dp[i] = dp[i - 1] + 2 + (pre > 0 ? dp[pre - 1] : 0);
                    max = Math.max(max, dp[i]);
                }
            }
        }
        return max;
    }
}


