package com.leetcode.solutions;

import org.junit.Test;

/**
 * Created by zhangwj on 16/3/22.
 */
public class Palindrome_Partitioning_II_132 {


    /**
     * DP方式解决
     *
     * @param s
     * @return
     */
    public int minCut(String s) {

        if (s == null || s.length() == 0) {
            return 0;
        }
        boolean[][] flag = new boolean[s.length()][s.length()];

        int[] len = new int[s.length() + 1];
        len[0] = -1;
        for (int i = 1; i <= s.length(); i++) {
            len[i] = Integer.MAX_VALUE;
            for (int j = 0; j < i; j++) {
                flag[j][i - 1] = s.charAt(j) == s.charAt(i - 1) && (i - j <= 2 || flag[j + 1][i - 2]);
                if (flag[j][i - 1]) {
                    len[i] = Math.min(len[i], len[j] + 1);
                }
            }
        }
        return len[s.length()];
    }

    @Test
    public void testpartition() {
        int aab = minCut("ab");
        System.out.println(aab);

    }

}
