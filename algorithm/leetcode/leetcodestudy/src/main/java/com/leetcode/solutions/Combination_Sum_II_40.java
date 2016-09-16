/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * @author zhangwj
 */
public class Combination_Sum_II_40 {

    @Test
    public void main() {
        int[] candidates = {10, 1, 2, 7, 6, 1, 5};
        int target = 8;
        System.out.println(combinationSum2(candidates, target));
    }


    public static List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> results = new ArrayList<>();

        Arrays.sort(candidates);
        get(results, new ArrayList<Integer>(), candidates, 0, target);
        return results;
    }

    public static void get(List<List<Integer>> sets, List<Integer> tempRes, int[] candidade, int index, int target) {
        if (target == 0) {
            sets.add(new ArrayList<Integer>(tempRes));
            return;
        }
        if (index >= candidade.length || candidade[index] > target || target < 0) {
            return;
        }

        for (int i = index; i < candidade.length && candidade[index] <= target; i++) {
            if (i > index && candidade[i] == candidade[i - 1]) {
                continue;
            }
            tempRes.add(candidade[i]);
            get(sets, tempRes, candidade, i + 1, target - candidade[i]);
            tempRes.remove(tempRes.size() - 1);
        }
    }
}
