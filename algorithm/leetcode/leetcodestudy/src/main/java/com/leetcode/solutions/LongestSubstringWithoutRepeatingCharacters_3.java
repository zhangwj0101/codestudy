/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import org.junit.Test;

import java.math.BigDecimal;
import java.util.Arrays;

/**
 * @author zhangwj
 */
public class LongestSubstringWithoutRepeatingCharacters_3 {


    @Test
    public void test() {

    }


    public int lengthOfLongestSubstring3(String s) {
        if (s == null) {
            return 0;
        }
        if (s.length() <= 1) {
            return s.length();
        }
        int[] table = new int[255];
        Arrays.fill(table, -1);
        int left = 0;
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            if (table[s.charAt(i)] >= left) {
                left = table[s.charAt(i)] + 1;
            }
            table[s.charAt(i)] = i;
            if (i - left > end - start) {
                end = i;
                start = left;
            }
        }
        return end - start + 1;
    }
}
