/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

/**
 *
 * @author zhangwj
 */
public class Search_in_Rotated_Sorted_Array_33 {

    public static int search(int[] nums, int target) {
        int i = 0;
        if (nums.length < 1) {
            return -1;
        }
        if (nums[0] == target) {
            return 0;
        } else if (nums[0] < target) {
            for (i = 0; i < nums.length && nums[i] < target; i++);
            return i == nums.length ? -1 : nums[i] == target ? i : -1;
        } else {
            for (i = nums.length - 1; i >= 0 && nums[i] > target; i--);
            return i == -1 ? -1 : nums[i] == target ? i : -1;
        }
    }

}
