package com.leetcode.solutions;

import java.util.*;

/**
 * Created by zhangwj on 16/3/3.
 */
public class Subsets_II_90 {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        Set<List<Integer>> sresults = new HashSet<>();
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
            sresults.add(sub);
        }
        for (List<Integer> sub : sresults) {
            results.add(sub);
        }
        return results;
    }

}
