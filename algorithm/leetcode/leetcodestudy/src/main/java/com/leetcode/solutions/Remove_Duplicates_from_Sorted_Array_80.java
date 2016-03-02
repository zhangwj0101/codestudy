package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/2.
 */
public class Remove_Duplicates_from_Sorted_Array_80 {
    public int removeDuplicates(int[] nums) {

        if (nums.length <= 2) {
            return nums.length;
        }
        int i = 2;
        int pointer = 0;
        while (i < nums.length && nums[i] != nums[i - 2]) {
            i++;
        }
        if (i == nums.length) {
            return nums.length;
        }
        pointer = i;
        i++;
        while (i < nums.length) {
            if (nums[i] != nums[pointer - 2]) {
                nums[pointer++] = nums[i];
                nums[pointer] = 0;
            }
            i++;
        }

        return pointer;
    }
}
