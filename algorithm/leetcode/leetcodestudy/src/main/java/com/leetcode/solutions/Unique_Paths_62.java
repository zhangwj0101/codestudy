package com.leetcode.solutions;

import org.junit.Test;

/**
 * Created by zhangwj on 16/2/29.
 */
public class Unique_Paths_62 {

    @Test
    public void test() {
        System.out.println(uniquePaths(3, 3));
    }

    public int uniquePaths(int m, int n) {

        if (m == 1 || n == 1) {
            return 1;
        }
        int[][] weight = new int[m][n];
        for (int i = 1; i < m; i++) {
            weight[i][0] = 1;
        }
        for (int j = 1; j < n; j++) {
            weight[0][j] = 1;
        }
        for (int j = 1; j < n; j++) {
            for (int i = 1; i < m; i++) {
                weight[i][j] = weight[i][j - 1] + weight[i - 1][j];
            }
        }
        return weight[m - 1][n - 1];
    }
}
