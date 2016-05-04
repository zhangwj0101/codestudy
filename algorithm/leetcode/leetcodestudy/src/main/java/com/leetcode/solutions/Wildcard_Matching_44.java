package com.leetcode.solutions;


import org.junit.Test;

import java.util.Arrays;

/**
 * Created by zhangwj on 16/2/23.
 */

public class Wildcard_Matching_44 {


    @Test
    public void main() {
        String s = "aa", p = "a*";
        System.out.println(isMatch1(s, p));
    }

    /**
     * 递归方式
     *
     * @param s
     * @param p
     * @param si
     * @param pi
     * @return
     */
    public boolean match(String s, String p, int si, int pi) {

        if (pi >= p.length()) {
            return si >= s.length();
        }
        if (si >= s.length()) {
            while (pi < p.length() && p.charAt(pi) == '*') {
                pi++;
            }
            return pi >= p.length();
        }
        if (s.charAt(si) == p.charAt(pi) || p.charAt(pi) == '?') {
            return match(s, p, si + 1, pi + 1);
        } else {
            if (p.charAt(pi) == '*') {
                for (int i = si; i <= s.length(); i++) {
                    if (match(s, p, i, pi + 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    public boolean isMatch(String s, String p) {
        return match(s, p, 0, 0);
    }

    /**
     * 动态规划方法
     *
     * @param s
     * @param p
     * @return
     */
    public boolean isMatch1(String s, String p) {
        boolean[][] flag = new boolean[p.length()][s.length()];
        if (p.length() < 1) {
            return s.length() < 1;
        }
        if (s.length() < 1) {
            int i = 0;
            for (; i < p.length() && p.charAt(i) == '*'; i++) ;
            return i == p.length();
        }

        boolean t = false;
        if (p.charAt(0) == '*') {
            Arrays.fill(flag[0], true);
        } else if (p.charAt(0) == '?' || p.charAt(0) == s.charAt(0)) {
            t = flag[0][0] = true;
        }
        for (int i = 1; i < p.length() && flag[i - 1][0]; i++) {
            if (p.charAt(i) == '*') {
                flag[i][0] = true;
            } else if (p.charAt(i) == '?' || p.charAt(i) == s.charAt(0)) {
                if (t) {
                    break;
                }
                flag[i][0] = true;
                t = true;
            } else {
                break;
            }
        }
        for (int i = 1; i < p.length(); i++) {
            for (int j = 1; j < s.length(); j++) {
                if (p.charAt(i) == s.charAt(j) || p.charAt(i) == '?') {
                    flag[i][j] = flag[i - 1][j - 1];
                } else if (p.charAt(i) == '*') {
                    flag[i][j] = flag[i - 1][j] || flag[i][j - 1];
                }
            }
        }
        return flag[p.length() - 1][s.length() - 1];
    }
}
