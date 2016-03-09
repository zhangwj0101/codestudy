package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/9.
 */
public class Unique_Binary_Search_Trees_96 {

    public int numTrees(int n) {

        if (n < 1) {
            return 1;
        }
        int[] nums = new int[n + 1];
        nums[0] = 1;
        nums[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int k = 1; k <= i; k++) {
                nums[i] += nums[k - 1] * nums[i - k];
            }
        }
        return nums[n];
    }
}
