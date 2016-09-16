package com.leetcode.solutions;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by zwj on 2016/5/5.
 */
public class Two_Sum_1 {

    @Test
    public void test() {
        Object objs = new Object[10];
        System.out.println(objs.getClass());

    }

    public int[] twoSum2(int[] nums, int target) {

        Map<Integer, Integer> maps = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (maps.containsKey(nums[i])) {
                return new int[]{maps.get(nums[i]), i};
            }
            maps.put(target - nums[i], i);
        }

        return null;
    }
}
