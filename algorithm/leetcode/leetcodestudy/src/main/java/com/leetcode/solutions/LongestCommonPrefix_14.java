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
public class LongestCommonPrefix_14 {

    @Test
    public void test() {
        String[] s = {"'", "s", "dsf"};
        System.out.println(longestCommonPrefix(s));
    }

    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length < 1) {
            return "";
        }
        int i = 0;
        boolean flag = true;
        String te = strs[0];

        while (flag) {
            for (String t : strs) {
                if (t == null
                        || t.length() <= i
                        || t.charAt(i) != te.charAt(i)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                i++;
            }
        }
        return te.substring(0, i);
    }

}
