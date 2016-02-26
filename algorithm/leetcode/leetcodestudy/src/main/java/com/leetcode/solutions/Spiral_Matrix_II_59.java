package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/2/25.
 */
public class Spiral_Matrix_II_59 {
    public static void main(String[] args) {
        int n = 1;
        int[][] s = generateMatrix(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.printf("%3d", s[i][j]);
            }
            System.out.println();
        }
    }

    public static int[][] generateMatrix(int n) {


        int[][] matrix = new int[n][n];
        if (n < 1) {
            return matrix;
        }
        int t = (n + 1) / 2;
        int poi = 1;
        for (int k = 0; k < t; k++) {
            for (int j = k; j <= matrix[0].length - 1 - k; j++) {
                matrix[k][j] = poi++;
            }
            for (int i = k + 1; i <= matrix.length - 1 - k; i++) {
                matrix[i][matrix[0].length - 1 - k] = poi++;
            }

            for (int j = matrix[0].length - 1 - k - 1; j >= k; j--) {
                matrix[matrix.length - 1 - k][j] = poi++;
            }
            for (int i = matrix.length - 1 - k - 1; i > k; i--) {
                matrix[i][k] = poi++;
            }
        }
        return matrix;
    }
}
