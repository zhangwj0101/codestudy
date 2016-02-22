/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 *
 * @author zhangwj
 */
public class Combination_Sum_II_40 {

    public static void main(String[] args) {
        int[] candidates = {1};
        int target = 1;
        System.out.println(combinationSum2(candidates, target));
    }

    public static void get(int[] candidates,
                           int index, int target,
                           List<Integer> tempResult, Set<List<Integer>> results) {

        if (target == 0) {
            List<Integer> de = new ArrayList<>();
            for (Integer temp : tempResult) {
                de.add(temp);
            }
            results.add(de);
            return;
        }
        if (index >= candidates.length) {
            return;
        }
        for (int i = index; i < candidates.length && candidates[i] <= target; i++) {
            tempResult.add(candidates[i]);
            get(candidates, i + 1, target - candidates[i], tempResult, results);
            tempResult.remove(tempResult.size() - 1);

        }
    }

    public static List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> results = new ArrayList<>();
        Set<List<Integer>> sresults = new HashSet<>();
        List<Integer> tempResults = new ArrayList<>();

        Arrays.sort(candidates);
        get(candidates, 0, target, tempResults, sresults);
        for (List<Integer> te : sresults) {
            results.add(te);
        }
        return results;
    }
}
