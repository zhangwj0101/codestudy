/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import org.junit.Test;

import java.util.Arrays;

/**
 * @author zhangwj
 */
public class Implement_strStr_28 {

    @Test
    public void test() {
        System.out.println(strStr("a", ""));
    }

    public int strStr(String haystack, String needle) {
        if (haystack.equals(needle) || needle.length() < 1) {
            return 0;
        }
        int i = 0, j = 0;
        int[] next = getNext(needle);
        while (i < haystack.length() && j < needle.length()) {
            if (j == -1 || haystack.charAt(i) == needle.charAt(j)) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        return j == needle.length() ? i - j : -1;
    }

    private int[] getNext(String needle) {
        int[] next = new int[needle.length()];
        next[0] = -1;
        int k = -1, j = 0;
        while (j < needle.length() - 1) {
            if (k == -1 || needle.charAt(k) == needle.charAt(j)) {
                k++;
                j++;
                if (needle.charAt(k) == needle.charAt(j)) {
                    next[j] = next[k];
                } else {
                    next[j] = k;
                }
            } else {
                k = next[k];
            }
        }
        return next;
    }
}
