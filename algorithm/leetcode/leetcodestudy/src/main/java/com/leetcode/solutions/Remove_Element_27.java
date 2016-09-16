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
public class Remove_Element_27 {

    @Test
    public void main() {
        int[] nums = {3, 2, 2, 3};
        int val = 3;
        System.out.println(removeElement(nums, val));
        System.out.println(Arrays.toString(nums));
    }

    public static int removeElement(int[] nums, int val) {

        int point = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != val) {
                nums[point] = nums[i];
                point++;
            }
        }
        return point;
    }

}
