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
public class Remove_Duplicates_from_Sorted_Array_26 {

    @Test
    public void main() {

        int[] nums = {1, 1, 2};
        System.out.println(removeDuplicates(nums));
    }


    public int removeDuplicates(int[] nums) {

        if (nums.length == 0) {
            return 0;
        }
        int pointer = 1, last = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > last) {
                nums[pointer++] = nums[i];
            }
            last = nums[i];
        }

        return pointer;
    }
}
