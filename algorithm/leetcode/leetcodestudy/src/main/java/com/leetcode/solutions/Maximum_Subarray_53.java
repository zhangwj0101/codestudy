package com.leetcode.solutions;

import org.omg.CORBA.INTERNAL;

/**
 * Created by zhangwj on 16/2/25.
 */
public class Maximum_Subarray_53 {

    public static void main(String[] args) {
        int[] nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        System.out.println(maxSubArray(nums));
    }

    public static int maxSubArray(int[] nums) {
        int sum = Integer.MIN_VALUE;
        int subsum = Integer.MIN_VALUE;

        for (int i = 0; i < nums.length; i++) {

            if (subsum < 0) {
                subsum = nums[i];
            } else {
                subsum += nums[i];
            }
            sum = sum >= subsum ? sum : subsum;
        }
        return sum;
    }
}
