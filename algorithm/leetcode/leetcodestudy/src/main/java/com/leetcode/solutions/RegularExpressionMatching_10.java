/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

/**
 * @author zhangwj
 */
public class RegularExpressionMatching_10 {

    public static void main(String[] args) {
        String s = "ab";
        System.out.println(s.substring(2));
    }

    public static boolean isMatch(String s, String p) {
        return s.matches(p);
    }

    public boolean isMatch2(String s, String p) {
        int lens = s.length();
        int lenp = p.length();
        if (lens == 0 && lenp == 0) {
            return true;
        }

        // init
        boolean[][] dp = new boolean[2][lenp + 1];
        dp[0][0] = dp[1][0] = true;
        for (int j = 2; j <= lenp; ++j) {
            if (p.charAt(j - 1) == '*' && dp[0][j - 2]) {
                dp[0][j] = dp[1][j] = true;
            }
        }
        // dp
        for (int i = 1; i <= lens; ++i) {
            dp[i & 1][0] = false;
            for (int j = 1; j <= lenp; ++j) {
                dp[i & 1][j] = ((p.charAt(j - 1) == s.charAt(i - 1) || p.charAt(j - 1) == '.') && dp[1 - (i & 1)][j - 1])
                        || p.charAt(j - 1) == '*' && (p.charAt(j - 2) == s.charAt(i - 1) || p.charAt(j - 2) == '.') && dp[1 - (i & 1)][j]
                        || (j >= 2 && p.charAt(j - 1) == '*' && dp[i & 1][j - 2]);
            }
        }

        return dp[lens & 1][lenp];
    }

    public boolean isMatch3(String s, String p) {
        // base case
        if (p.length() == 0) {
            return s.length() == 0;
        }
        // special case
        if (p.length() == 1) {
            // if the length of s is 0, return false
            if (s.length() < 1) {
                return false;
            } //if the first does not match, return false
            else if ((p.charAt(0) != s.charAt(0)) && (p.charAt(0) != '.')) {
                return false;
            } // otherwise, compare the rest of the string of s and p.
            else {
                return isMatch(s.substring(1), p.substring(1));
            }
        }
        // case 1: when the second char of p is not '*'
        if (p.charAt(1) != '*') {
            if (s.length() < 1) {
                return false;
            }
            if ((p.charAt(0) != s.charAt(0)) && (p.charAt(0) != '.')) {
                return false;
            } else {
                return isMatch(s.substring(1), p.substring(1));
            }
        } // case 2: when the second char of p is '*', complex case.
        else {
            //case 2.1: a char & '*' can stand for 0 element
            if (isMatch(s, p.substring(2))) {
                return true;
            }
            //case 2.2: a char & '*' can stand for 1 or more preceding element, 
            //so try every sub string
            int i = 0;
            while (i < s.length() && (s.charAt(i) == p.charAt(0) || p.charAt(0) == '.')) {
                if (isMatch(s.substring(i + 1), p.substring(2))) {
                    return true;
                }
                i++;
            }
            return false;
        }
    }

    public boolean isMatch4(String s, String p) {

        if (p.length() == 0) {
            return s.length() == 0;
        }
        //p's length 1 is special case    
        if (p.length() == 1 || p.charAt(1) != '*') {
            if (s.length() < 1 || (p.charAt(0) != '.' && s.charAt(0) != p.charAt(0))) {
                return false;
            }
            return isMatch(s.substring(1), p.substring(1));
        } else {
            int len = s.length();
            int i = -1;
            while (i < len && (i < 0 || p.charAt(0) == '.' || p.charAt(0) == s.charAt(i))) {
                if (isMatch(s.substring(i + 1), p.substring(2))) {
                    return true;
                }
                i++;
            }
            return false;
        }
    }
}
