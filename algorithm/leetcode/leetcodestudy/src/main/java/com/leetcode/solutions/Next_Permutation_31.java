/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import java.util.Arrays;

/**
 *
 * @author zhangwj
 */
public class Next_Permutation_31 {

    public static void main(String[] args) {
        int[] nums = {5, 4, 7, 5, 3, 2};
        nextPermutation(nums);
        for (int i = 0; i < nums.length; i++) {
            System.out.printf("%4d,", nums[i]);
        }
    }

    public static void nextPermutation(int[] nums) {

        if (nums.length < 2) {
            return;
        }
        int i = 0;
        for (i = nums.length - 1; i > 0 && nums[i] < nums[i - 1]; i--);
        if (i == 0) {
            Arrays.sort(nums);
            return;
        }

        int k = i + 1;
        for (; k < nums.length && nums[k] > nums[i - 1]; k++);
        k--;
        int temp = nums[i - 1];
        nums[i - 1] = nums[k];
        nums[k] = temp;
        Arrays.sort(nums, i, nums.length);

    }

    public static void nextPermutation1(int[] nums) {

        if (nums.length < 2) {
            return;
        }
        int i = 0;
        for (i = nums.length - 1; i > 0 && nums[i] <= nums[i - 1]; i--);
        if (i == 0) {
            Arrays.sort(nums);
            return;
        }
        int k = i + 1;
        for (; k < nums.length && nums[k] >= nums[i]; k++);
        k++;
        int temp = nums[nums.length - 1];
        int j = 0;
        boolean flag = temp > nums[i - 1];
        if (flag) {
            for (j = nums.length - 1; j >= i; j--) {
                nums[j] = nums[j - 1];
            }
        } else {
            temp = nums[i - 1];
            for (j = i - 1; j < nums.length - 1; j++) {
                nums[j] = nums[j + 1];
            }
        }
        nums[j] = temp;
    }
}
