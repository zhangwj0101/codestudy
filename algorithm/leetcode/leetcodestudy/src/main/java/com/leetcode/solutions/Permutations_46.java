package com.leetcode.solutions;

import java.awt.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by zhangwj on 16/2/24.
 */
public class Permutations_46 {
    public static void main(String[] args) {
        int[] nums = {1, 2, 3};
        System.out.println(permute(nums));
    }

    public static void get(int[] nums, int index, List<List<Integer>> results) {
        if (index >= nums.length - 1) {
            List<Integer> sub = new ArrayList<>(nums.length);
            for (int i = 0; i < nums.length; i++) {
                sub.add(nums[i]);
            }
            results.add(sub);
            return;
        }
        for (int i = index; i < nums.length; i++) {
            int t = nums[index];
            nums[index] = nums[i];
            nums[i] = t;
            get(nums, index + 1, results);
            t = nums[index];
            nums[index] = nums[i];
            nums[i] = t;
        }
    }

    public static List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> results = new ArrayList<>();
        get(nums, 0, results);
        return results;

    }
}

