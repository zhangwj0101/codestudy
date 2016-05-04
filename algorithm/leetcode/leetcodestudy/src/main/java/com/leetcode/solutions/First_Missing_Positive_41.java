/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import org.junit.Test;

/**
 * @author zhangwj
 */
public class First_Missing_Positive_41 {

    @Test
    public void main() {
        int[] nums = {3, 4, -1, 1};
        System.out.println(firstMissingPositive(nums));
    }

    public int firstMissingPositive(int[] nums) {
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

    public int firstMissingPositive1(int[] A) {
        if (A == null) {
            return 0;
        }

        int len = A.length;
        for (int i = 0; i < len; i++) {

            while (A[i] <= len && A[i] > 0 && A[A[i] - 1] != A[i]) {
                swap(A, i, A[i] - 1);
            }
        }

        for (int i = 0; i < len; i++) {
            if (A[i] != i + 1) {
                return i + 1;
            }
        }

        return len + 1;
    }

    public static void swap(int[] A, int i, int j) {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }

}
