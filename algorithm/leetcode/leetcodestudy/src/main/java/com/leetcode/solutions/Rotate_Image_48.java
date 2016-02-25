package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/2/25.
 */
public class Rotate_Image_48 {
    public static void main(String[] args) {
        int[][] matrix = {{1, 2}, {3, 4}};
        rotate(matrix);
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix.length; j++) {
                System.out.printf("%4d", matrix[i][j]);
            }
            System.out.println("");
        }

    }

    public static void rotate(int[][] matrix) {

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < i; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (int k = 0; k < matrix.length / 2; k++) {
            for (int i = 0; i < matrix.length; i++) {
                int temp = matrix[i][k];
                matrix[i][k] = matrix[i][matrix.length - 1 - k];
                matrix[i][matrix.length - 1 - k] = temp;
            }
        }
    }
}
