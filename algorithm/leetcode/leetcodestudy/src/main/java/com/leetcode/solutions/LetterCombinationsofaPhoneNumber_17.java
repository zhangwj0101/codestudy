/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author zhangwj
 */
public class LetterCombinationsofaPhoneNumber_17 {

    public static void main(String[] args) {
        LetterCombinationsofaPhoneNumber_17 t = new LetterCombinationsofaPhoneNumber_17();
        List<String> letterCombinations = t.letterCombinations("23");
        System.out.println(letterCombinations);
    }

    public static List<String> letterCombinations1(String digits) {

        String[] nums = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv",
                         "wxyz"};
        List<String> buildResults = new ArrayList<>();
        char[] digs = digits.toCharArray();
        if (digits.length() == 0) {
            return buildResults;
        }
        char[] ts = nums[digs[0] - '0'].toCharArray();
        for (int j = 0; j < ts.length; j++) {
            buildResults.add(String.valueOf(ts[j]));
        }
        for (int i = 1; i < digs.length; i++) {
            ts = nums[digs[i] - '0'].toCharArray();
            List<String> tempLists = new ArrayList<>();
            for (int k = 0; k < ts.length; k++) {
                for (String temp : buildResults) {
                    tempLists.add(String.format("%s%c", temp, ts[k]));
                }
            }
            buildResults.clear();
            buildResults = tempLists;
        }
        return buildResults;
    }

    public static List<String> get(List<String> strs, int i) {
        List<String> tempLists = new ArrayList<>();
        char[] ts = strs.get(i).toCharArray();
        if (i == strs.size() - 1) {
            for (int j = 0; j < ts.length; j++) {
                tempLists.add(String.valueOf(ts[j]));
            }
            return tempLists;
        }
        List<String> buildResults = get(strs, i + 1);
        for (int k = 0; k < ts.length; k++) {
            for (String temp : buildResults) {
                tempLists.add(String.format("%c%s", ts[k], temp));
            }
        }
        return tempLists;
    }

    public static List<String> letterCombinations2(String digits) {

        String[] nums = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv",
                         "wxyz"};
        List<String> buildResults = new ArrayList<>();
        char[] digs = digits.toCharArray();
        if (digits.length() == 0) {
            return buildResults;
        }
        for (int i = 0; i < digs.length; i++) {
            int t = digs[i] - '0';
            if (t > 1 && t < 10) {
                buildResults.add(nums[t]);
            }
        }
        List<String> t = get(buildResults, 0);

        return t;
    }

    private String[] alpha = new String[]{
        "",
        "1", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };
    private StringBuilder word;

    private void dfs(List<String> res, String digits, int cur) {
        if (cur >= digits.length()) {
            res.add(word.toString());
        } else {
            for (int i = 0; i < alpha[digits.charAt(cur) - '0'].length(); ++i) {
                word.append(alpha[digits.charAt(cur) - '0'].charAt(i));
                dfs(res, digits, cur + 1);
                word.deleteCharAt(word.length() - 1);
            }
        }
    }

    public List<String> letterCombinations(String digits) {
        List<String> ret = new ArrayList<>();
        word = new StringBuilder();
        if (digits.length() == 0) {
            return ret;
        }
        dfs(ret, digits, 0);
        return ret;
    }
}
