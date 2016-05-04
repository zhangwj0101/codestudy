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

    /*
        Solution 3: 使用四条bound来限制的方法.
    */
    public int[][] generateMatrix1(int n) {
        int[][] ret = new int[n][n];
        if (n == 0) {
            return ret;
        }

        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int num = 1;
        while (top <= bottom) {
            if (top == bottom) {
                ret[top][top] = num++;
                break;
            }

            // first line.
            for (int i = left; i < right; i++) {
                ret[top][i] = num++;
            }
            // right line;
            for (int i = top; i < bottom; i++) {
                ret[i][right] = num++;
            }
            // bottom line;
            for (int i = right; i > left; i--) {
                ret[bottom][i] = num++;
            }
            // left line;
            for (int i = bottom; i > top; i--) {
                ret[i][left] = num++;
            }
            top++;
            bottom--;
            left++;
            right--;
        }

        return ret;
    }
}
