/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import org.junit.Test;

/**
 * @author zhangwj
 */
public class LongestPalindromicSubstring_5 {

    @Test
    public void test() {
        String s = "sddss";
        System.out.println(longestPalindromeC(s));
    }


    /*
       常规方法
    */
    public String longestPalindromeC(String s) {
        if (s == null || s.length() <= 1 || new StringBuilder(s).reverse().toString().equals(s)) {
            return s;
        }

        String result = "";
        for (int i = 1; i < s.length(); i++) {
            int j = 1;
            //奇数对称情况 比如aba
            for (j = 1; i + j < s.length() && i - j >= 0 && s.charAt(i + j) == s.charAt(i - j); j++) ;
            String temp1 = s.substring(i - j + 1, i + j);
            if (temp1.length() > result.length()) {
                result = temp1;
            }
            //偶数情况 aa类型
            if (s.charAt(i) == s.charAt(i - 1)) {
                for (j = 1; i + j < s.length() && i - j - 1 >= 0 && s.charAt(i + j) == s.charAt(i - j - 1); j++) ;
                String temp2 = s.substring(i - j, i + j);
                if (temp2.length() > result.length()) {
                    result = temp2;
                }
            }
        }
        return result;
    }

    /*
        标记数组加DP方法
     */
    public String longestPalindromeDP(String s) {
        if (s == null || s.length() == 0) {
            return s;
        }
        boolean[][] flag = new boolean[s.length()][s.length()];
        int start = 0;
        int end = 0;

        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j <= i; j++) {
                flag[j][i] = s.charAt(j) == s.charAt(i) && (i - j <= 2 || flag[j + 1][i - 1]);
                if (flag[j][i]) {
                    if (end - start < i - j) {
                        start = j;
                        end = i;
                    }
                }
            }
        }
        return s.substring(start, end + 1);
    }

    /*
       DP方法
    */
    public String longestPalindromeDPB(String s) {
        int[] p = new int[2048];
        StringBuilder t = new StringBuilder("$");
        for (int i = 0; i < s.length(); ++i) {
            t.append('#');
            t.append(s.charAt(i));
        }
        t.append("#_");
        // mx为已判断回文串最右边位置，id为中间位置，mmax记录p数组中最大值
        int mx = 0, id = 0, mmax = 0;
        int right = 0;
        for (int i = 1; i < t.length() - 1; i++) {
            p[i] = mx > i ? Math.min(p[2 * id - i], mx - i) : 1;
            while (t.charAt(i + p[i]) == t.charAt(i - p[i]))
                p[i]++;
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
            if (mmax < p[i]) {
                mmax = p[i];
                right = i;
            }
        }
        // 最长为mmax - 1
        return s.substring(right / 2 - mmax / 2, right / 2 - mmax / 2 + mmax - 1);
    }


}
