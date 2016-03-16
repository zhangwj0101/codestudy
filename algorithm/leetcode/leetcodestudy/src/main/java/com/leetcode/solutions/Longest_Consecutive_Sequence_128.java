package com.leetcode.solutions;


import org.junit.Test;

import java.util.HashSet;
import java.util.Set;
import java.util.TreeMap;

/**
 * Created by zwj on 2016/3/13.
 */
public class Longest_Consecutive_Sequence_128 {
    public int longestConsecutive(int[] num) {
        if (num == null) {
            return 0;
        }

        HashSet<Integer> set = new HashSet<Integer>();
        for (int i : num) {
            set.add(i);
        }

        int max = 0;
        for (int i : num) {
            int cnt = 1;
            set.remove(i);

            int tmp = i - 1;
            while (set.contains(tmp)) {
                set.remove(tmp);
                cnt++;
                tmp--;
            }
            tmp = i + 1;
            while (set.contains(tmp)) {
                set.remove(tmp);
                cnt++;
                tmp++;
            }

            max = Math.max(max, cnt);
        }

        return max;
    }

    @Test
    public void test() {
        int[] nums = {100, 4, 200, 1, 3, 2};
        System.out.println(longestConsecutive(nums));
    }

}
