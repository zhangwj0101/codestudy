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
public class Sum3Closest_16 {

    public static void main(String[] args) {
        int[] nums = {1, 2, 4, 8, 16, 32, 64, 128};
        System.out.println(threeSumClosest(nums, 82));
    }

    public static int threeSumClosest(int[] nums, int target) {

        int result = 0;
        if (nums.length < 3) {
            return 0;
        }
        Arrays.sort(nums);

        int j = nums.length - 1;
        result = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < j - 1; i++) {
            for (int k = i + 1; k < j;) {
                int temp = nums[i] + nums[k] + nums[j];
                if (temp < target) {
                    k++;
                } else if (temp > target) {
                    j--;
                } else {
                    return target;
                }

                result = Math.abs(result - target) > Math.abs(temp - target) ? temp : result;
            }
            j = nums.length-1;
        }
        return result;
    }

}
