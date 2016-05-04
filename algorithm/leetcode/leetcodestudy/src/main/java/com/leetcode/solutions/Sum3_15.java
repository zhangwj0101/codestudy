/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

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

    public static void main(String[] args) {
        int[] s = {0, 0, 0, 0};
        threeSum(s);
    }

    public static List<List<Integer>> threeSum(int[] nums) {

        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0, j = nums.length - 1; i < j - 1; i++) {
            for (int k = i + 1; k < j; ) {
                if (nums[i] + nums[k] + nums[j] > 0) {
                    j--;
                } else if (nums[i] + nums[k] + nums[j] < 0) {
                    k++;
                } else {
                    res.add(Arrays.asList(nums[i], nums[k], nums[j]));
                    j--;
                    k++;
                    while (k < j && nums[k] == nums[k - 1]) {
                        k++;
                    }
                    while (k < j && nums[j] == nums[j + 1]) {
                        j--;
                    }
                }
            }
            j = nums.length - 1;
            while (i <= j - 2 && nums[i] == nums[i + 1]) {
                ++i;
            }
        }

        return res;
    }
}
