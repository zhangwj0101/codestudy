/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

/**
 *
 * @author zhangwj
 */
public class LongestPalindromicSubstring_5 {

    public static void main(String[] args) {
        String s = "sdfs";
        System.out.println(longestPalindrome(s));
    }

    /**
     * o(n)
     *
     * @param s
     * @return
     */
    public static String longestPalindrome(String s) {
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
            while (t.charAt(i + p[i]) == t.charAt(i - p[i])) {
                p[i]++;
            }
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
