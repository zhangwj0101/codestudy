package com.leetcode.solutions;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by zhangwj on 16/3/22.
 */
public class Palindrome_Partitioning_131 {

    /*
    直接DFS
     */
    public void dfs(String s, int i, List<List<String>> results, List<String> tempResult) {
        if (i >= s.length()) {
            results.add(new ArrayList<>(tempResult));
            return;
        }
        for (int j = i; j < s.length(); j++) {
            String temp = s.substring(i, j + 1);
            if (new StringBuilder(temp).reverse().toString().equals(temp)) {
                tempResult.add(temp);
                dfs(s, j + 1, results, tempResult);
                tempResult.remove(tempResult.size() - 1);
            }
        }
    }
    //////////////////////////


    /**
     * DFS+记忆法解决问题
     *
     * @param s
     * @return
     */
    public boolean[][] buildPalindromDP(String s) {
        boolean[][] result = new boolean[s.length()][s.length()];

        for (int j = 0; j < s.length(); j++) {
            result[j][j] = true;
            for (int i = j - 1; i >= 0; i--) {
                result[i][j] = s.charAt(j) == s.charAt(i) && (j - i <= 2 || result[i + 1][j - 1]);
            }
        }
        return result;
    }

    public void get(String s, int i, List<List<String>> results, List<String> tempResult, boolean[][] tag) {

        if (i >= s.length()) {
            results.add(new ArrayList<String>(tempResult));
            return;
        }
        for (int j = i; j < s.length(); j++) {
            if (tag[i][j]) {
                String te = s.substring(i, j + 1);
                tempResult.add(te);
                get(s, j + 1, results, tempResult, tag);
                tempResult.remove(tempResult.size() - 1);
            }
        }
    }

    ///////////////////////////////////


    public List<List<String>> partition(String s) {

        List<List<String>> results = new ArrayList<>();

        dfs(s, 0, results, new ArrayList<String>());
        return results;
    }

    public List<List<String>> partition1(String s) {

        List<List<String>> results = new ArrayList<>();
        boolean[][] res = buildPalindromDP(s);
        get(s, 0, results, new ArrayList<String>(), res);
        return results;
    }

    /*
    DP方法
     */
    public List<List<String>> partitionDP(String s) {

        List<List<String>>[] results = new ArrayList[s.length()];
        boolean[][] res = buildPalindromDP(s);
        for (int i = s.length() - 1; i >= 0; i--) {
            results[i] = new ArrayList<>();
            for (int j = i; j < s.length(); j++) {
                if (res[i][j]) {
                    String temp = s.substring(i, j + 1);
                    if (j + 1 < s.length()) {
                        List<List<String>> result = results[j + 1];
                        for (List<String> ts : result) {
                            List sa = new ArrayList<String>(ts);
                            sa.add(0, temp);
                            results[i].add(sa);
                        }
                    } else {
                        results[i].add(Arrays.asList(temp));
                    }
                }
            }
        }
        return results[0];
    }


    @Test
    public void testpartition() {
        List<List<String>> aab = partition1("ccaacabacb");
        System.out.println(aab);

    }


}
