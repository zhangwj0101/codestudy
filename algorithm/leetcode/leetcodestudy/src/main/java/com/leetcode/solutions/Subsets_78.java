package com.leetcode.solutions;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by zhangwj on 16/3/2.
 */
public class Subsets_78 {

    public static void main(String[] args) {
        int[] nums = {1, 2, 3};
        List<String> s = new ArrayList<>();
        System.out.println(new Subsets_78().subsets(nums));
    }

    public List<List<Integer>> subsets(int[] nums) {

        Arrays.sort(nums);
        List<List<Integer>> results = new ArrayList<>();
        int len = (int) Math.pow(2, nums.length);
        boolean[] flags = new boolean[nums.length];
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < flags.length; j++) {
                if (!flags[j]) {
                    flags[j] = true;
                    break;
                }
                flags[j] = false;
            }
            List<Integer> sub = new ArrayList<>();
            for (int j = 0; j < flags.length; j++) {
                if (flags[j]) {
                    sub.add(nums[j]);
                }
            }
            results.add(sub);
        }
        return results;
    }
}
