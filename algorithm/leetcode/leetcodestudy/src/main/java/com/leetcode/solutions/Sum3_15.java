/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * @author zhangwj
 */
public class Sum3_15 {

    @Test
    public void test() {
        int[] s = {-1, 0, 1, 2, -1, -4};
        System.out.println(threeSum1(s));
    }

    public List<List<Integer>> threeSum1(int[] nums) {

        List<List<Integer>> res = new ArrayList<>();

        if (nums == null || nums.length < 3) {
            return res;
        }
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int start = i + 1, end = nums.length - 1;
            while (start < end) {
                int tempsum = nums[i] + nums[start] + nums[end];
                if (tempsum == 0) {
                    res.add(Arrays.asList(nums[i], nums[start], nums[end]));
                    start++;
                    end--;
                    while (start < end && nums[start] == nums[start - 1]) {
                        start++;
                    }
                    while (start < end && nums[end] == nums[end + 1]) {
                        end--;
                    }
                } else if (tempsum > 0) {
                    end--;
                } else {
                    start++;
                }
            }

        }
        return res;
    }

    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> results = new ArrayList<>();
        int start = 0, target = 0;
        Arrays.sort(nums);
        System.out.println(Arrays.toString(nums));
        for (int i = start; i < nums.length - 2; i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int end = nums.length - 1;
            while (left < end) {
                if (nums[i] + nums[left] + nums[end] == target) {
                    List<Integer> temRes = new ArrayList<>();
                    temRes.add(nums[i]);
                    temRes.add(nums[left]);
                    temRes.add(nums[end]);
                    results.add(temRes);
                    left++;
                    end--;
                    while (left < end && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (end > left && nums[end] == nums[end + 1]) {
                        end--;
                    }

                } else if (nums[i] + nums[left] + nums[end] > target) {
                    end--;
                } else {
                    left++;
                }
            }
        }
        return results;
    }
}
