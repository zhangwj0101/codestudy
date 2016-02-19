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
public class Remove_Element_27 {

    public static void main(String[] args) {

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
