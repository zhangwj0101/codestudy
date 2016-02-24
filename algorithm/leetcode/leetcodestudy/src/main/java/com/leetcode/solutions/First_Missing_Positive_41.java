/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

/**
 * @author zhangwj
 */
public class First_Missing_Positive_41 {

    public static void main(String[] args) {
        int[] nums = {3, 4, -1, 1};
        System.out.println(firstMissingPositive(nums));
    }

    public static int firstMissingPositive(int[] nums) {
        int[] buffer = new int[1024];
        int i = 0;
        for (i = 0; i < nums.length; i++) {
            if (nums[i] > 0) {
                buffer[nums[i]] = 1;
            }
        }
        for (i = 1; i < buffer.length; i++) {
            if (buffer[i] == 0) {
                break;
            }
        }
        return i;
    }
}
