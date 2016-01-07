/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import java.math.BigDecimal;

/**
 *
 * @author zhangwj
 */
public class LongestSubstringWithoutRepeatingCharacters_3 {

    public static void main(String[] args) {

//        System.out.println(lengthOfLongestSubstring("abbbb"));
//        System.out.println(findLongestDifLength("abbbb"));
        BigDecimal unpaidAmount = new BigDecimal(505);
        BigDecimal dealAmount = new BigDecimal(490);
        //真实收益率 ＝ (剩余本息－实际投标金额)*365/(实际投标金额*可获得的收益天数)
        BigDecimal actualRate = unpaidAmount.subtract(dealAmount)
                .multiply(new BigDecimal(365))
                .divide(dealAmount.multiply(new BigDecimal(31)), 4, BigDecimal.ROUND_HALF_UP);
        System.out.println(actualRate);

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
