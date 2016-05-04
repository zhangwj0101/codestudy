/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author zhangwj
 */
public class Sum4_18 {

    public static void main(String[] args) {
        int[] nums = {-3, -2, -1, 0, 0, 1, 2, 3};
        int target = 0;
        System.out.println(fourSum(nums, target));
    }

    public static List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> results = new ArrayList<>();

        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 3; ) {
            int subTarget = target - nums[i];

            for (int k = i + 1; k < nums.length - 2; ) {
                int end = nums.length - 1;
                for (int t = k + 1; t < end; ) {
                    if (nums[k] + nums[t] + nums[end] < subTarget) {
                        t++;
                    } else if (nums[k] + nums[t] + nums[end] > subTarget) {
                        end--;
                    } else {
                        results.add(Arrays.asList(nums[i], nums[k], nums[t], nums[end]));
                        int tempt = t++;
                        int tempend = end--;
                        while (t < end && nums[t] == nums[tempt]) {
                            t++;
                        }
                        while (end > t && nums[end] == nums[tempend]) {
                            end--;
                        }
                    }
                }

                int tempk = k++;
                while (k < nums.length - 2 && nums[k] == nums[tempk]) {
                    k++;
                }
            }
            int tempk = i++;
            while (i < nums.length - 3 && nums[i] == nums[tempk]) {
                i++;
            }
        }
        return results;
    }

}
