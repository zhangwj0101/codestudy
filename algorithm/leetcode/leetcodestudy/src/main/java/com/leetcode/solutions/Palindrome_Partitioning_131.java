package com.leetcode.solutions;

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by zhangwj on 16/3/22.
 */
public class Palindrome_Partitioning_131 {
    public List<List<String>> partition(String s) {

        List<List<String>> results = new ArrayList<>();

        get(s, 0, results, new ArrayList<String>());
        return results;
    }

    public void get(String s, int i, List<List<String>> results, List<String> tempResult) {

        if (i >= s.length()) {
            results.add(new ArrayList<String>(tempResult));
            return;
        }
        for (int j = i; j < s.length(); j++) {
            String te = s.substring(i, j + 1);
            if (new StringBuilder(te).reverse().toString().equals(te)) {
                tempResult.add(te);
                get(s, j + 1, results, tempResult);
                tempResult.remove(tempResult.size() - 1);
            }
        }
        return;
    }


    public boolean[][] buildPalindromDP(String s) {
        boolean[][] result = new boolean[s.length()][s.length()];

        for (int i = 0; i < s.length() - 1; i++) {
            result[i][i + 1] = s.charAt(i) == s.charAt(i + 1);
            result[i][i] = true;
        }
        result[s.length() - 1][s.length() - 1] = true;
        for (int len = 2; len < s.length(); len++) {
            for (int j = 0; j + len < s.length(); j++) {
                result[j][j + len] = result[j + 1][j + len - 1] && s.charAt(j) == s.charAt(j + len);
            }
        }
        return result;
    }

    public void get1(String s, int i, List<List<String>> results, List<String> tempResult, boolean[][] tag) {

        if (i >= s.length()) {
            results.add(new ArrayList<String>(tempResult));
            return;
        }
        for (int j = i; j < s.length(); j++) {
            if (tag[i][j]) {
                String te = s.substring(i, j + 1);
                tempResult.add(te);
                get1(s, j + 1, results, tempResult, tag);
                tempResult.remove(tempResult.size() - 1);
            }
        }
    }

    public List<List<String>> partition1(String s) {

        List<List<String>> results = new ArrayList<>();
        boolean[][] res = buildPalindromDP(s);
        get1(s, 0, results, new ArrayList<String>(), res);
        return results;
    }

    @Test
    public void testpartition() {
        List<List<String>> aab = partition1("ccaacabacb");
        System.out.println(aab);

    }
}
