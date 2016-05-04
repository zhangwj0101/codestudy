/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

/**
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
            for (i = 0; i < nums.length && nums[i] < target; i++) ;
            return i == nums.length ? -1 : nums[i] == target ? i : -1;
        } else {
            for (i = nums.length - 1; i >= 0 && nums[i] > target; i--) ;
            return i == -1 ? -1 : nums[i] == target ? i : -1;
        }
    }

    public int search1(int[] A, int target) {
        if (A == null || A.length == 0) {
            return -1;
        }
        int l = 0;
        int r = A.length - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (A[mid] == target) {
                return mid;
            }

            // left side is sorted.
            // BUG 1: if don't use >= , and use L < r in while loop, than there is some problem.
            if (A[mid] >= A[l]) {
                if (target > A[mid] || target < A[l]) {
                    // move to right;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                if (target < A[mid] || target > A[r]) {
                    // move to left;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }

        return -1;
    }

}
