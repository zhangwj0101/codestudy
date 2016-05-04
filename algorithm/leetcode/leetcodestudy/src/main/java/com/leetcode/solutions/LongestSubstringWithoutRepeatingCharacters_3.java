/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import java.math.BigDecimal;

/**
 * @author zhangwj
 */
public class LongestSubstringWithoutRepeatingCharacters_3 {

    public static void main(String[] args) {

//        System.out.println(lengthOfLongestSubstring("abbbb"));
//        System.out.println(findLongestDifLength("abbbb"));
    }

    public static int findLongestDifLength(String s) {
        long star = System.nanoTime();
        char[] a = s.toCharArray();
        int tempLen = 0, i = 0;
        int j = i + 1;

        if (s.length() == 0) {
            return 0;
        }
        while (i < a.length && j < a.length) {
            for (int t = i; t < j; t++) {
                if (a[t] == a[j]) {
                    tempLen = (tempLen > j - i) ? tempLen : j - i;
                    i = t + 1;
                    break;
                }
            }
            j++;
        }
        System.out.println(System.nanoTime() - star);
        return tempLen > j - i ? tempLen : j - i;
    }

    public static int lengthOfLongestSubstring(String s) {
        long start = System.nanoTime();
        int res = 0, left = 0;
        byte prev[] = new byte[300];

        // init prev array  
        for (int i = 0; i < 300; ++i) {
            prev[i] = -1;
        }

        for (int i = 0; i < s.length(); ++i) {
            if (prev[s.charAt(i)] >= left) {
                left = prev[s.charAt(i)] + 1;
            }
            prev[s.charAt(i)] = (byte) i;
            if (res < i - left + 1) {
                res = i - left + 1;
            }
        }
        System.out.println(System.nanoTime() - start);
        return res;
    }
}
