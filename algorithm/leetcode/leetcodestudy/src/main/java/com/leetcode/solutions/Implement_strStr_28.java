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

        System.out.println(strStr1("a", ""));
    }

    public int strStr(String haystack, String needle) {

        if (haystack.length() < needle.length()) {
            return -1;
        }
        int point1 = 0;
        int subpoint = 0;
        char[] s1 = haystack.toCharArray();
        char[] s2 = needle.toCharArray();
        while (point1 < s1.length && subpoint < s2.length) {
            if (s1[point1] == s2[subpoint]) {
                point1++;
                subpoint++;
            } else {
                if (subpoint == 0) {
                    point1++;
                } else {
                    point1 = point1 - subpoint + 1;
                }
                subpoint = 0;
            }
        }
        if (subpoint == s2.length) {
            return point1 - subpoint;
        }

        return -1;

    }

    public int strStr1(String haystack, String needle) {

        if (haystack.equals(needle) || needle.length() == 0) {
            return 0;
        }
        if (haystack.length() < needle.length()) {
            return -1;
        }

        int[] next = getNext(needle);
        System.out.println(Arrays.toString(next));
        int j = 0, i = 0;
        while (i < haystack.length() && j < needle.length()) {
            if (haystack.charAt(i) == needle.charAt(j)) {
                i++;
                j++;
            } else {
                if (next[j] == -1) {
                    i++;
                    j = 0;
                } else {
                    j = next[j];
                }
            }
            if (j == needle.length()) {
                return i - j;
            }
        }
        return -1;
    }

    public int[] getNext(String needle) {
        int[] next = new int[needle.length()];
        int k = -1, i = 0;
        next[0] = -1;
        while (i < needle.length() - 1) {
            if (k == -1 || needle.charAt(i) == needle.charAt(k)) {
                i++;
                k++;
                next[i] = k;
            } else {
                k = next[k];
            }
        }
        return next;
    }
}
