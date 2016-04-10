package com.leetcode.solutions;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by zhangwj on 16/3/2.
 */
public class Subsets_78 {

    @Test
    public void test() {
        int[] nums = {1, 2, 3};
        System.out.println(new Subsets_78().subsets1(nums));
    }


    public List<List<Integer>> subsets(int[] nums) {

        Arrays.sort(nums);
        List<List<Integer>> results = new ArrayList<>();
        int len = (int) Math.pow(2, nums.length);
        boolean[] flags = new boolean[nums.length];
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < flags.length; j++) {
                if (!flags[j]) {
                    flags[j] = true;
                    break;
                }
                flags[j] = false;
            }
            List<Integer> sub = new ArrayList<>();
            for (int j = 0; j < flags.length; j++) {
                if (flags[j]) {
                    sub.add(nums[j]);
                }
            }
            results.add(sub);
        }
        return results;
    }

    public List<List<Integer>> subsets1(int[] S) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        if (S == null) {
            return ret;
        }

        Arrays.sort(S);

        dfs(S, 0, new ArrayList<Integer>(), ret);

        return ret;
    }

    public void dfs(int[] S, int index, List<Integer> path, List<List<Integer>> ret) {
        ret.add(new ArrayList<Integer>(path));

        for (int i = index; i < S.length; i++) {
            path.add(S[i]);
            dfs(S, i + 1, path, ret);
            path.remove(path.size() - 1);
        }
    }
}
