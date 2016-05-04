/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import java.util.ArrayList;
import java.util.List;

/**
 * @author zhangwj
 */
public class Generate_Parentheses_22 {

    public static void main(String[] args) {

        System.out.println(generateParenthesis1(3));
    }

    public static void get(String input, List<String> result, int n) {
        if (n == 0) {
            if (!result.contains(input)) {
                result.add(input);
            }
            return;
        }
        for (int i = 0; i <= input.length() / 2; i++) {
            StringBuilder sb = new StringBuilder(input);
            get(sb.insert(i, "()").toString(), result, n - 1);
        }
    }

    public static List<String> generateParenthesis(int n) {

        List<String> results = new ArrayList<>();
        if (n == 0) {
            return results;
        }

        get("()", results, n - 1);

        return results;
    }

    public static void get1(char[] input, List<String> result, int cur, int end) {

        if (cur >= input.length - 1 || end < 0) {
            return;
        }
//        result.add(String.valueOf(input));
        for (int i = cur - 1; i > end; i--) {
            char temp = input[cur];
            input[cur] = input[i];
            input[i] = temp;
            result.add(String.valueOf(input));
            get1(input, result, cur + 1, i);
            temp = input[cur];
            input[cur] = input[i];
            input[i] = temp;
        }
    }

    public static List<String> generateParenthesis1(int n) {

        List<String> results = new ArrayList<>();
        if (n == 0) {
            return results;
        }
        char left = '(', right = ')';
        char[] input = new char[n * 2];
        for (int i = 0; i < n * 2; i++) {
            if (i < n) {
                input[i] = left;
            } else {
                input[i] = right;
            }
        }
        get1(input, results, n, 0);
        return results;
    }

}
