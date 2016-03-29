package com.leetcode.solutions;


import org.junit.Test;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.TreeMap;

/**
 * Created by zwj on 2016/3/13.
 */
public class Longest_Consecutive_Sequence_128 {

    /**
     * Set集合的办法
     *
     * @param num
     * @return
     */
    public int longestConsecutive(int[] num) {
        if (num == null || num.length == 0) {
            return 0;
        }
        int max = 0;
        Set<Integer> sets = new HashSet<>();
        for (int i = 0; i < num.length; i++) {
            sets.add(num[i]);
        }
        for (int i = 0; i < num.length; i++) {
            int tempMax = 0;
            int t = num[i];
            while (sets.contains(t)) {
                sets.remove(t);
                t--;
                tempMax++;
            }
            t = num[i] + 1;
            while (sets.contains(t)) {
                sets.remove(t);
                t++;
                tempMax++;
            }
            max = Math.max(max, tempMax);
        }
        return max;
    }

    @Test
    public void test() {
        int[] nums = {0, -1};
        System.out.println(longestConsecutive(nums));
    }

}
