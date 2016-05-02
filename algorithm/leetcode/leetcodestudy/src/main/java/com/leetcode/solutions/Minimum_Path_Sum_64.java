package com.leetcode.solutions;

import org.junit.Test;

/**
 * Created by zhangwj on 16/2/29.
 */
public class Minimum_Path_Sum_64 {

    @Test
    public void test() {
        int[][] grid = {{9, 1, 4, 8}};
        System.out.println(minPathSum(grid));
    }

    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        if (m == 1 && n == 1) {
            return grid[0][0];
        }
        int[][] weight = new int[m][n];
        weight[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            weight[i][0] = weight[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            weight[0][j] = weight[0][j - 1] + grid[0][j];
        }
        for (int j = 1; j < n; j++) {
            for (int i = 1; i < m; i++) {
                weight[i][j] = Math.min(weight[i][j - 1], weight[i - 1][j]) + grid[i][j];
            }
        }
        return weight[m - 1][n - 1];
    }

    public int get(int[][] grid, int i, int j) {

        if (i == 0 && j == 0) {
            return 0;
        }
        if (i < 0 || j < 0) {
            return 10000;
        }
        return Math.min(get(grid, i - 1, j), get(grid, i, j - 1)) + grid[i][j];
    }

    public int minPathSum1(int[][] grid) {
        return get(grid, grid.length - 1, grid[0].length - 1);
    }


}
