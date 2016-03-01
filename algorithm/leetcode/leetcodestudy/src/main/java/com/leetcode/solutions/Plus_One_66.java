package com.leetcode.solutions;

import java.util.Arrays;

/**
 * Created by zhangwj on 16/3/1.
 */
public class Plus_One_66 {
    public static void main(String[] args) {

    }

    public int[] plusOne(int[] digits) {

        int left = 0;
        digits[digits.length - 1] += 1;
        for (int i = digits.length - 1; i >= 0; i--) {
            int temp = digits[i] + left;
            digits[i] = temp % 10;
            left = temp / 10;
        }
        if (left != 0) {
            int[] nums = new int[digits.length + 1];
            nums[0] = left;
            for (int i = 1; i < nums.length; i++) {
                nums[i] = digits[i - 1];
            }
            return nums;
        } else {
            return digits;
        }
    }
}
