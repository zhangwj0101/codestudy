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
public class Implement_strStr_28 {

    public static void main(String[] args) {

        System.out.println(strStr("mississippi", "issip"));
    }

    public static int strStr(String haystack, String needle) {

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
}
