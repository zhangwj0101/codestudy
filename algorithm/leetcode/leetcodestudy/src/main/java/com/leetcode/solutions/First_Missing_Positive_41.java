/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import org.junit.Test;

import java.util.Arrays;

/**
 * @author zhangwj
 */
public class First_Missing_Positive_41 {

    @Test
    public void main() {
        int[] nums = {1, 1};
        System.out.println(firstMissingPositive2(nums));
    }


    public int firstMissingPositive2(int[] nums) {
        if (nums == null) {
            return 0;
        }

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != i + 1) {
                while (nums[i] > 0 && nums[i] <= nums.length && nums[nums[i] - 1] != nums[i]) {
                    swap(nums, i, nums[i] - 1);
                }
            }
        }
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.length + 1;
    }

    public static void swap(int[] nums, int i, int j) {
        int ch = nums[i];
        nums[i] = nums[j];
        nums[j] = ch;
    }
}
