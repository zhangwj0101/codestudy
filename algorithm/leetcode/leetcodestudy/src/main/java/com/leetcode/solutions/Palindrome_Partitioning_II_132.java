package com.leetcode.solutions;

import org.junit.Test;

/**
 * Created by zhangwj on 16/3/22.
 */
public class Palindrome_Partitioning_II_132 {

    public int minCut(String s) {

        if (new StringBuilder(s).reverse().toString().equals(s)) {
            return 0;
        }
        int[][] map = new int[s.length()][s.length()];

        for (int k = 1; k < s.length(); k++) {
            int j = s.length() - 1;
            for (int i = s.length() - k - 1; i >= 0; i--, j--) {
                String te = s.substring(i, j + 1);
                if (new StringBuilder(te).reverse().toString().equals(te)) {
                    map[i][j] = 0;
                    continue;
                }
                int t = Integer.MAX_VALUE;
                for (int m = i; m < j; m++) {
                    t = Math.min(t, map[i][m] + map[m + 1][j] + 1);
                }
                map[i][j] = t;
            }
        }
        return map[0][s.length() - 1];
    }

    private boolean[][] getIsPalindrome(String s) {
        boolean[][] isPalindrome = new boolean[s.length()][s.length()];

        for (int i = 0; i < s.length(); i++) {
            isPalindrome[i][i] = true;
        }
        for (int i = 0; i < s.length() - 1; i++) {
            isPalindrome[i][i + 1] = (s.charAt(i) == s.charAt(i + 1));
        }

        for (int length = 2; length < s.length(); length++) {
            for (int start = 0; start + length < s.length(); start++) {
                isPalindrome[start][start + length]
                        = isPalindrome[start + 1][start + length - 1] && s.charAt(start) == s.charAt(start + length);
            }
        }

        return isPalindrome;
    }

    public int minCut1(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }

        // preparation
        boolean[][] isPalindrome = getIsPalindrome(s);

        // initialize
        int[] f = new int[s.length() + 1];
        f[0] = 0;

        // main
        for (int i = 1; i <= s.length(); i++) {
            f[i] = Integer.MAX_VALUE; // or f[i] = i
            for (int j = 0; j < i; j++) {
                if (isPalindrome[j][i - 1]) {
                    f[i] = Math.min(f[i], f[j] + 1);
                }
            }
        }
        return f[s.length()] - 1;
    }

    public int minCut2(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }

        int len = s.length();

        // D[i]: 前i 个字符切为回文需要的切割数
        int[] D = new int[len + 1];
        D[0] = -1;

        // P[i][j]: S.sub(i-j) is a palindrome.
        boolean[][] P = new boolean[len][len];

        for (int i = 1; i <= len; i++) {
            // The worst case is cut character one by one.
            D[i] = i - 1;
            for (int j = 0; j <= i - 1; j++) {
                P[j][i - 1] = false;
                if (s.charAt(j) == s.charAt(i - 1) && (i - 1 - j <= 2 || P[j + 1][i - 2])) {
                    P[j][i - 1] = true;
                    D[i] = Math.min(D[i], D[j] + 1);
                }
            }
        }

        return D[len];
    }

    @Test
    public void testpartition() {
        int aab = minCut("abcdeffedcba");
        System.out.println(aab);

    }

}
