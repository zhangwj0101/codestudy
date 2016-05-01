package com.leetcode.solutions;

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by zhangwj on 16/3/2.
 */
public class Combinations_77 {

    @Test
    public void test() {
        System.out.println(new Combinations_77().combine(4, 2));
    }

    public void get(int index, int n, int k, List<List<Integer>> results, List<Integer> sub) {
        if (sub.size() == k) {
            results.add(new ArrayList<Integer>(sub));
            return;
        }
        for (int i = index; i <= n; i++) {
            sub.add(i);
            get(i + 1, n, k, results, sub);
            sub.remove(sub.size() - 1);
        }
    }

    public List<List<Integer>> combine(int n, int k) {

        List<List<Integer>> results = new ArrayList<>();
//        get(1, n, k, results, new ArrayList<Integer>());
        get1(new int[]{1, 2, 3, 4}, 0, 3, results, new ArrayList<Integer>());
        return results;

    }

    public void get1(int[] nums, int index, int k, List<List<Integer>> results, List<Integer> sub) {
        if (k == 0) {
            results.add(new ArrayList<Integer>(sub));
            return;
        }
        for (int i = index; i <= nums.length - k; i++) {
            sub.add(nums[i]);
            get1(nums, i + 1, k - 1, results, sub);
            sub.remove(sub.size() - 1);
        }
    }
}
