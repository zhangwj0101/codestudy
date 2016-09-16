/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import org.junit.Test;

import java.util.*;

/**
 * @author zhangwj
 */
public class Sum4_18 {

    @Test
    public void test() {
        int[] nums = {1, 0, -1, 0, -2, 2};
        int target = 0;
        System.out.println(fourSum1(nums, target));
    }


    public static List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> results = new ArrayList<>();

        Arrays.sort(nums);
        for (int i = 0; i <= nums.length - 4; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j <= nums.length - 3; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int start = j + 1, end = nums.length - 1;
                while (start < end) {
                    int tempSum = nums[i] + nums[j] + nums[start] + nums[end];
                    if (tempSum == target) {
                        results.add(Arrays.asList(nums[i], nums[j], nums[start], nums[end]));
                        start++;
                        end--;
                        while (start < end && nums[start] == nums[start - 1]) {
                            start++;
                        }
                        while (start < end && nums[end] == nums[end + 1]) {
                            end--;
                        }
                    } else if (tempSum > target) {
                        end--;
                    } else {
                        start++;
                    }
                }
            }
        }
        return results;
    }

    public List<List<Integer>> fourSum1(int[] nums, int target) {
        List<List<Integer>> results = new ArrayList<>();

        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            List<List<Integer>> lists = threeSum(nums, i + 1, target - nums[i]);
            if (lists.size() > 0) {
                for (List<Integer> t : lists) {
                    t.add(0, nums[i]);
                }
                results.addAll(lists);
            }
        }
        return results;
    }

    public List<List<Integer>> threeSum(int[] nums, int start, int target) {
        List<List<Integer>> results = new ArrayList<>();

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
