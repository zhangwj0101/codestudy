package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/2/24.
 */
public class Jump_Game_55 {
    public static void main(String[] args) {
        int[] nums = {3, 2, 1, 0, 4};
        System.out.println(canJump(nums));
    }

    public static boolean canJump(int[] nums) {
        int left_most = nums.length - 1;
        for (int i = nums.length - 2; i >= 0; i--) {
            if (i + nums[i] >= left_most) {
                left_most = i;
            }
        }
        return left_most == 0;
    }
}
