package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/15.
 */
public class Distinct_Subsequences_115 {
    public int numDistinct(String S, String T) {
        int[][] cnt = new int[T.length() + 1][S.length() + 1];
        for (int j = 0; j < S.length(); j++) {
            cnt[0][j] = 1;
        }
        for (int i = 1; i < T.length(); i++) {
            cnt[i][0] = 0;
        }

        for (int i = 1; i <= T.length(); i++) {
            for (int j = 1; j <= S.length(); j++) {
                if (T.charAt(i - 1) != S.charAt(j - 1)) {
                    cnt[i][j] = cnt[i][j - 1];    // The old way to match
                } else {    // Match, it allows us to have a new way to match
                    cnt[i][j] = cnt[i][j - 1] + cnt[i - 1][j - 1];    // old way + new way
                }
            }
        }

        return cnt[T.length()][S.length()];
    }

}
