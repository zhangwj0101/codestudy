/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import org.junit.Test;

import java.util.*;

/**
 * @author zhangwj
 */
public class Generate_Parentheses_22 {

    @Test
    public void test() {

        System.out.println(generateParenthesis1(3));
    }

    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        Set<String> resSets = new HashSet<>();
        gets(n, resSets);
        for (String te : resSets) {
            res.add(te);
        }
        return res;
    }

    public void gets(int n, Set<String> res) {
        if (n <= 1) {
            res.add("()");
            return;
        }
        Set<String> tempRes = new HashSet<>();
        gets(n - 1, tempRes);
        for (String te : tempRes) {
            for (int i = 0; i <= te.length(); i++) {
                res.add(new StringBuilder(te).insert(i, "()").toString());
            }
        }
    }

    public List<String> generateParenthesis1(int n) {
        List<String> res = new ArrayList<>();
        Set<String> sets = new HashSet<>();
        Set<String> sets2 = new HashSet<>();
        sets.add("()");
        for (int i = 2; i <= n; i++) {
            sets2.clear();
            for (String sb : sets) {
                for (int k = 0; k <= sb.length(); k++) {
                    sets2.add(new StringBuilder(sb).insert(k, "()").toString());
                }
            }
            sets.clear();
            sets.addAll(sets2);
        }
        for (String sb : sets) {
            res.add(sb);
        }
        return res;
    }
}
