/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

/**
 * @author zhangwj
 */
public class Search_for_Range_34 {

    public static void main(String[] args) {
        int[] nums = {5, 7, 7, 9, 8, 10};
        int target = 8;
        int[] result = searchRange(nums, target);
        System.out.println(result[0] + "," + result[1]);
    }

    public static int[] searchRange(int[] nums, int target) {
        int[] results = {-1, -1};
        int start = 0, end = nums.length - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                int temp = mid;
                while (temp >= 0 && nums[temp] == target) {
                    temp--;
                }
                results[0] = temp + 1;
                while (mid < nums.length && nums[mid] == target) {
                    mid++;
                }
                results[1] = mid - 1;
                break;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return results;
    }

}
