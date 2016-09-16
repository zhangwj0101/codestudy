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
public class Sum3Closest_16 {

    @Test
    public void test() {
        int[] nums = {1, 2, 4, 8, 16, 32, 64, 128};
        System.out.println(threeSumClosest(nums, 2));
    }

    public int threeSumClosest(int[] nums, int target) {
        if (nums == null || nums.length == 0 || nums.length < 3) {
            return 0;
        }
        Arrays.sort(nums);
        int tempSum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.length - 2; i++) {
            int start = i + 1;
            int end = nums.length - 1;
            while (start < end) {
                int temp = nums[i] + nums[start] + nums[end];
                tempSum = Math.abs(temp - target) > Math.abs(tempSum - target) ? tempSum : temp;
                if (temp == target) {
                    return target;
                } else if (temp > target) {
                    end--;
                } else {
                    start++;
                }
            }
        }
        return tempSum;
    }
}
