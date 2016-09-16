/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import java.util.Arrays;

/**
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
        int i = nums.length - 2, j = nums.length - 1;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i == -1) {
            Arrays.sort(nums);
            return;
        }
        while (j > i && nums[j] <= nums[i]) {
            j--;
        }
        swap(nums, i, j);
        Arrays.sort(nums, i + 1, nums.length);
    }

    public static void swap(int[] nums, int i, int j) {
        int te = nums[i];
        nums[i] = nums[j];
        nums[j] = te;
    }

}
