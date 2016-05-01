package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/2.
 */
public class Set_Matrix_Zeroes_73 {

    public void setZeroes(int[][] matrix) {

        if (matrix.length < 1) {
            return;
        }
        int[] m = new int[matrix.length];
        int[] n = new int[matrix[0].length];

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] == 0) {
                    m[i] = 1;
                    n[j] = 1;
                }
            }
        }
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (m[i] == 1 || n[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }

    }


}
