package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/4.
 */
public class Search_in_Rotated_Sorted_Array_II_81 {
    public boolean search(int[] A, int target) {
        for (int i = 0; i < A.length; i++) {
            if (A[i] == target) {
                return true;
            }
        }
        return false;
    }
}
