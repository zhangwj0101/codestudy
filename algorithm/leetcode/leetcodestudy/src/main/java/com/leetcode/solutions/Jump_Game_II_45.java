package com.leetcode.solutions;

import org.junit.Test;

/**
 * Created by zhangwj on 16/2/23.
 */
public class Jump_Game_II_45 {

    @Test
    public void main() {
        int[] nums = {2, 3, 1, 1, 4};
        System.out.println(jump1(nums));
    }

    public int jump1(int[] nums) {
        int last = 0;
        int cur = 0;
        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i > last) {
                last = cur;
                result++;
            }
            cur = Math.max(cur, i + nums[i]);
        }
        return result;
    }

    public int jump(int[] nums) {

        if (nums.length <= 1) {
            return 0;
        }
        if (nums[0] >= nums.length - 1) {
            return 1;
        }
        for (int j = 1; j <= nums[0]; j++) {
            if (j + nums[j] >= nums.length - 1) {
                return 2;
            }
        }
        int[] temps = new int[nums.length];
        for (int index = nums.length - 1; index >= 0; index--) {
            if (index + nums[index] >= nums.length - 1) {
                temps[index] = 1;
                continue;
            }
            if (nums[index] == 0) {
                temps[index] = nums.length;
                continue;
            }
            int minjumps = Integer.MAX_VALUE;
            for (int j = 1; j <= nums[index]; j++) {
                int te = 1 + temps[index + j];
                if (minjumps > te) {
                    minjumps = te;
                }
            }
            temps[index] = minjumps;
        }
        return temps[0];
    }


}
