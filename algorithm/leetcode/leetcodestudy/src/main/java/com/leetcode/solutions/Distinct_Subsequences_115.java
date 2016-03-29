package com.leetcode.solutions;

import org.junit.Test;

/**
 * Created by zhangwj on 16/3/15.
 */
public class Distinct_Subsequences_115 {


    public int numDistinct(String s, String t) {
        if (s.length() < t.length()) {
            return 0;
        }
        int[][] ways = new int[t.length() + 1][s.length() + 1];
        for (int j = 0; j < s.length(); j++) {
            ways[0][j] = 1;
        }
        for (int i = 1; i <= t.length(); i++) {
            for (int j = i; j <= s.length(); j++) {
                if (s.charAt(j - 1) == t.charAt(i - 1)) {
                    ways[i][j] = ways[i][j - 1] + ways[i - 1][j - 1];
                } else {
                    ways[i][j] = ways[i][j - 1];
                }
            }
        }
        return ways[t.length()][s.length()];
    }

    @Test
    public void test() {

    }
}
