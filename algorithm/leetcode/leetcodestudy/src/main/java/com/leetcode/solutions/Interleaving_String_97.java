package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/15.
 */
public class Interleaving_String_97 {

    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1 == null || s2 == null || s3 == null) {
            return false;
        }

        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();

        if (len1 + len2 != len3) {
            return false;
        }

        boolean[][] D = new boolean[len1 + 1][len2 + 1];

        for (int i = 0; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) {
                D[i][j] = false;
                if (i == 0 && j == 0) {
                    D[i][j] = true;
                    continue;
                }
                if (i != 0) {
                    D[i][j] |= s1.charAt(i - 1) == s3.charAt(i + j - 1) && D[i - 1][j];
                }
                if (j != 0) {
                    D[i][j] |= s2.charAt(j - 1) == s3.charAt(i + j - 1) && D[i][j - 1];
                }
            }
        }

        return D[len1][len2];
    }
}
