package com.leetcode.solutions;

/**
 * Created by zwj on 2016/9/5.
 */
public class House_Robber_198 {
    public static void main(String[] args) {
        int[] nums = {4, 5};
        System.out.println(rob(nums));
    }

    public static int rob(int[] nums) {

        if (nums == null || nums.length == 0) {
            return 0;
        }
        if (nums.length < 2) {
            return nums[0];
        }
        int[] mem = new int[nums.length];
        mem[0] = nums[0];
        mem[1] = Math.max(nums[0], nums[1]);
        for (int i = 2; i < nums.length; i++) {
            mem[i] = Math.max(nums[i] + mem[i - 2], mem[i - 1]);
        }
        return mem[mem.length - 1];
    }


}
