package com.leetcode.solutions;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * Created by zhangwj on 16/2/24.
 */
public class Permutations_II_47 {
    public static void main(String[] args) {
        int[] nums = {1, 1, 2, 2};
        System.out.println(permuteUnique(nums));
    }

    public static void get(int[] nums, int index, Set<List<Integer>> results) {
        if (index >= nums.length - 1) {
            List<Integer> sub = new ArrayList<>(nums.length);
            for (int i = 0; i < nums.length; i++) {
                sub.add(nums[i]);
            }
            results.add(sub);
            return;
        }
        for (int i = index; i < nums.length; i++) {
            if (i > index && nums[i] == nums[index]) {
                continue;
            }
            int t = nums[index];
            nums[index] = nums[i];
            nums[i] = t;
            get(nums, index + 1, results);
            t = nums[index];
            nums[index] = nums[i];
            nums[i] = t;
        }
    }

    public static List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> results = new ArrayList<>();
        Set<List<Integer>> sresults = new HashSet<>();
        get(nums, 0, sresults);
        for (List<Integer> t : sresults) {
            results.add(t);
        }
        return results;
    }
}
