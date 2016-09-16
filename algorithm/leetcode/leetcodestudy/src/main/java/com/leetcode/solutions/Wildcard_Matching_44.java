package com.leetcode.solutions;


import org.junit.Test;

import java.util.Arrays;

/**
 * Created by zhangwj on 16/2/23.
 */

public class Wildcard_Matching_44 {


    @Test
    public void main() {
        String s = "b", p = "*?*?";
        System.out.println(isMatch2(s, p));
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

    public boolean isMatch2(String s, String p) {
        boolean[][] matches = new boolean[p.length() + 1][s.length() + 1];
        matches[0][0] = true;
        for (int i = 1; i <= p.length(); i++) {
            if (p.charAt(i - 1) == '*') {
                matches[i][0] = matches[i - 1][0];
            }
        }
        for (int i = 1; i <= p.length(); i++) {
            for (int j = 1; j <= s.length(); j++) {
                if ((p.charAt(i - 1) == '?' || p.charAt(i - 1) == s.charAt(j - 1)) && matches[i - 1][j - 1]) {
                    matches[i][j] = true;
                } else if (p.charAt(i - 1) == '*') {
                    matches[i][j] = matches[i - 1][j] || matches[i][j - 1];
                }
            }
        }
        return matches[p.length()][s.length()];
    }
}
