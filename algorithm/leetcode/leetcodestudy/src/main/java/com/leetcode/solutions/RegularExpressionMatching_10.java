/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import org.junit.Test;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;

/**
 * @author zhangwj
 */
public class RegularExpressionMatching_10 {

    @Test
    public void test() throws Exception {
        System.out.println(isMatch("ab", "C*abc*"));
    }

    public boolean isMatch(String s, String p) {

        if (p.length() == 0) {
            return s.length() == 0;
        }
        if (p.length() == 1 || p.charAt(1) != '*') {
            if (s.length() < 1 || (p.charAt(0) != '.' && s.charAt(0) != p.charAt(0))) {
                return false;
            }
            return isMatch(s.substring(1), p.substring(1));
        } else {
            int len = s.length();
            int i = -1;
            while (i < len && (i < 0 || p.charAt(0) == '.' || p.charAt(0) == s.charAt(i))) {
                if (isMatch(s.substring(i + 1), p.substring(2))) {
                    return true;
                }
                i++;
            }
            return false;
        }
    }

    public boolean isMatch1(String s, String p) {
        if (s == null && p == null) {
            return true;
        }
        if (s == null || p == null) {
            return false;
        }

        boolean[][] flag = new boolean[p.length() + 1][s.length() + 1];

        flag[0][0] = true;

        for (int i = 1; i <= p.length(); i++) {
            if (p.charAt(i - 1) == '*' && (i < 2 || flag[i - 2][0])) {
                flag[i][0] = true;
            }
        }

        for (int i = 1; i <= p.length(); i++) {
            for (int j = 1; j <= s.length(); j++) {
                if ((p.charAt(i - 1) == s.charAt(j - 1) || p.charAt(i - 1) == '.')
                        && flag[i - 1][j - 1]) {
                    flag[i][j] = true;

                } else if (i >= 2 && p.charAt(i - 1) == '*' && flag[i - 2][j]) {
                    flag[i][j] = true;
                } else if (i >= 2 && p.charAt(i - 1) == '*'
                        && (p.charAt(i - 2) == s.charAt(j - 1) || p.charAt(i - 2) == '.')
                        && flag[i][j - 1]) {
                    flag[i][j] = true;
                }

            }
        }

        return flag[p.length()][s.length()];
    }


}




















