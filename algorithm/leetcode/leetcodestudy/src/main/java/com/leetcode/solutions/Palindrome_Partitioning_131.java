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

    @Test
    public void testpartition() {
        List<List<String>> aab = partition("aba");
        System.out.println(aab);

    }
}
