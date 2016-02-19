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
public class Remove_Duplicates_from_Sorted_Array_26 {

    public static void main(String[] args) {

        int[] nums = {1, 1, 2};
        System.out.println(removeDuplicates(nums));
    }

    public static int removeDuplicates(int[] nums) {

        if (nums.length == 0) {
            return 0;
        }
        int t = nums[0];
        int len = 1;
        int point = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == t) {
                continue;
            } else {
                nums[point] = nums[i];
                point++;
                t = nums[i];
            }
        }
        return point;
    }
}
