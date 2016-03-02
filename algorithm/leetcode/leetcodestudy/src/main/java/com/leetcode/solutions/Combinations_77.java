package com.leetcode.solutions;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by zhangwj on 16/3/2.
 */
public class Combinations_77 {

    public static void main(String[] args) {
        System.out.println(new Combinations_77().combine(4, 2));
    }

    public void get(int index, int n, int k, List<List<Integer>> results, List<Integer> sub) {
        if (sub.size() == k) {
            List<Integer> su = new ArrayList<>();
            su.addAll(sub);
            results.add(su);
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
        get(1, n, k, results, new ArrayList<Integer>());
        return results;

    }
}
