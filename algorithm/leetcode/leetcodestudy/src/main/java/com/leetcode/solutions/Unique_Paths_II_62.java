package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/2/29.
 */
public class Unique_Paths_II_62 {

    public int uniquePathsWithObstacles(int[][] obstacleGrid) {

        int[][] weight = new int[obstacleGrid.length][obstacleGrid[0].length];
        for (int i = 0; i < obstacleGrid.length && obstacleGrid[i][0] != 1; i++) {
            weight[i][0] = 1;
        }
        for (int j = 0; j < obstacleGrid[0].length && obstacleGrid[0][j] != 1; j++) {
            weight[0][j] = 1;
        }
        for (int j = 1; j < obstacleGrid[0].length; j++) {
            for (int i = 1; i < obstacleGrid.length; i++) {
                if (obstacleGrid[i][j] == 1) {
                    weight[i][j] = 0;
                } else {
                    weight[i][j] = weight[i][j - 1] + weight[i - 1][j];
                }

            }
        }
        return weight[obstacleGrid.length - 1][obstacleGrid[0].length - 1];
    }
}
