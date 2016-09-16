package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/2.
 */
public class Remove_Duplicates_from_Sorted_Array_80 {
    public int removeDuplicates(int[] nums) {
        if (nums == null)
            return 0;
        int cur = 0;
        int i, j;
        for (i = 0; i < nums.length; ) {
            int now = nums[i];
            for (j = i; j < nums.length; j++) {
                if (nums[j] != now)
                    break;
                if (j - i < 2)
                    nums[cur++] = now;
            }
            i = j;
        }
        return cur;
    }
}
