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
public class LongestCommonPrefix_14 {

    public static void main(String[] args) {
        String[] s = {"'", "s", "dsf"};
        System.out.println(longestCommonPrefix(s));
    }

    public static String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) {
            return "";
        }
        int pointer = 0;
        String t = strs[0];

        boolean flag = true;
        while (flag) {
            for (String str : strs) {
                if (str.length() == 0
                    || pointer >= str.length()
                    || t.charAt(pointer) != str.charAt(pointer)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                pointer++;
            }
        }
        return strs[0].substring(0, pointer);
    }
}
