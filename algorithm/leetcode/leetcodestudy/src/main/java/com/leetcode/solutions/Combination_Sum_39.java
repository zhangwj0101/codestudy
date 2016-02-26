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
public class Combination_Sum_39 {

    public static void main(String[] args) {
        int[] c = {1, 2};
        int target = 3;
        List<List<Integer>> res = combinationSum(c, target);
        System.out.println(res.size());
    }

    public static void get(int[] candidates,
                           int index, int target,
                           List<Integer> tempResult, List<List<Integer>> results) {

        if (target == 0) {

            List<Integer> de = new ArrayList<>();
            for (Integer temp : tempResult) {
                de.add(temp);
            }
            results.add(de);
            return;
        }
        for (int i = index; i < candidates.length && candidates[i] <= target; i++) {
            if (i == 0 || candidates[i] != candidates[i - 1]) {
                tempResult.add(candidates[i]);
                get(candidates, i, target - candidates[i], tempResult, results);
                tempResult.remove(tempResult.size() - 1);
            }
        }
    }

    public static List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> results = new ArrayList<>();
        List<Integer> tempResults = new ArrayList<>();
        Arrays.sort(candidates);
        get(candidates, 0, target, tempResults, results);
        return results;
    }
}
