/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author zhangwj
 */
public class LetterCombinationsofaPhoneNumber_17 {


    @Test
    public void test() {
        List<String> letterCombinations = letterCombinations1("23");
        System.out.println(letterCombinations);
    }

    private void dfs(List<String> res, String digits, int cur, StringBuilder word, String[] alpha) {
        if (cur >= digits.length()) {
            res.add(word.toString());
        } else {
            for (int i = 0; i < alpha[digits.charAt(cur) - '0'].length(); ++i) {
                word.append(alpha[digits.charAt(cur) - '0'].charAt(i));
                dfs(res, digits, cur + 1, word, alpha);
                word.deleteCharAt(word.length() - 1);
            }
        }
    }

    public List<String> letterCombinations(String digits) {
        List<String> ret = new ArrayList<>();
        String[] alpha = new String[]{
                "",
                "1", "abc", "def",
                "ghi", "jkl", "mno",
                "pqrs", "tuv", "wxyz"
        };
        StringBuilder word = new StringBuilder();
        if (digits.length() == 0) {
            return ret;
        }
        dfs(ret, digits, 0, word, alpha);
        return ret;
    }

    public List<String> letterCombinations1(String digits) {
        String[] alpha = new String[]{
                "",
                "1", "abc", "def",
                "ghi", "jkl", "mno",
                "pqrs", "tuv", "wxyz"
        };

        List<String> res = new ArrayList<>();
        if (digits.length() < 1) {
            return res;
        }
        get(res, digits.toCharArray(), new StringBuilder(), 0, alpha);
        return res;
    }

    public void get(List<String> res, char[] sts, StringBuilder sb, int index, String[] alpha) {
        if (index >= sts.length) {
            res.add(sb.toString());
            return;
        }
        for (char ch : alpha[sts[index] - '0'].toCharArray()) {
            sb.append(ch);
            get(res, sts, sb, index + 1, alpha);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}
