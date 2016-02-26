package com.leetcode.solutions;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by zhangwj on 16/2/25.
 */
public class Spiral_Matrix_54 {

    public static void main(String[] args) {
//        int[][] matrix = {{1, 11}, {2, 12}, {3, 13}, {4, 14}, {5, 15}};
        int[][] matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
        System.out.println(spiralOrder(matrix));
    }

    public static List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> results = new ArrayList<>();
        if (matrix.length < 1) {
            return results;
        }
        int t = (Math.min(matrix.length, matrix[0].length) + 1) / 2;
        int row = matrix.length, col = matrix[0].length;
        for (int k = 0; k < t; k++, row -= 2, col -= 2) {
            for (int j = k; j <= matrix[0].length - 1 - k; j++) {
                results.add(matrix[k][j]);
            }
            for (int i = k + 1; i <= matrix.length - 1 - k; i++) {
                results.add(matrix[i][matrix[0].length - 1 - k]);
            }
            if (row == 1 || col == 1) {
                break;
            }
            for (int j = matrix[0].length - 1 - k - 1; j >= k; j--) {
                results.add(matrix[matrix.length - 1 - k][j]);
            }
            for (int i = matrix.length - 1 - k - 1; i > k; i--) {
                results.add(matrix[i][k]);
            }
        }
        return results;
    }
}
