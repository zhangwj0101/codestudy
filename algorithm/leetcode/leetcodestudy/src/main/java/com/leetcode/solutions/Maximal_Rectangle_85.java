package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/4.
 */
public class Maximal_Rectangle_85 {

    public static void main(String[] args) {
        char[][] matrix = {{'1'}};
        Maximal_Rectangle_85 m = new Maximal_Rectangle_85();
        m.maximalRectangle(matrix);
    }

    public int get(int[] nums) {
        int sum = 0;
        int subsum = 0;
        for (int i = 0; i < nums.length; i++) {
            if (subsum > 0) {
                subsum += nums[i];
            } else {
                subsum = nums[i];
            }
            sum = sum > subsum ? sum : subsum;
        }
        return sum;
    }

    public int maximalRectangle(char[][] matrix) {
        int sum = 0;
        for (int i = 0; i < matrix.length; i++) {
            int[] temp = new int[matrix[0].length];
            for (int j = i; j < matrix.length; j++) {
                for (int k = 0; k < temp.length; k++) {
                    temp[k] += (matrix[j][k] == '0' ? -10000 : 1);
                }
                int subsum = get(temp);
                sum = sum > subsum ? sum : subsum;
            }
        }
        return sum;
    }
}
