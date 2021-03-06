package com.leetcode.solutions;

import org.junit.Test;

/**
 * Created by zhangwj on 16/3/1.
 */
public class Search_2D_Matrix_74 {

    public boolean searchMatrix(int[][] matrix, int target) {


        int start = 0, end = matrix.length - 1, first;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (matrix[mid][matrix[0].length - 1] == target) {
                return true;
            } else if (matrix[mid][matrix[0].length - 1] < target) {
                start = mid + 1;
            } else {
                if (mid - 1 >= 0 && matrix[mid - 1][matrix[0].length - 1] < target) {
                    start = mid;
                    break;
                }
                end = mid - 1;
            }
        }
        if (start >= matrix.length) {
            return false;
        }
        first = start;
        start = 0;
        end = matrix[0].length - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (matrix[first][mid] == target) {
                return true;
            } else if (matrix[first][mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return false;
    }


    @Test
    public void test() {
        searchMatrix1(new int[][]{{1}}, 1);
    }

    public boolean searchMatrix1(int[][] matrix, int target) {

        if (matrix == null) {
            return false;
        }
        int col = matrix[0].length - 1;
        int row = matrix.length - 1;
        int pointy = col, pointx = 0;
        while (!(pointx < 0 || pointx > row || pointy < 0 || pointy > col)) {
            if (matrix[pointx][pointy] == target) {
                return true;
            } else if (matrix[pointx][pointy] > target) {
                pointy--;
            } else {
                pointx++;
            }
        }
        return false;
    }
}
