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
public class StringTonteger_8 {

    @Test
    public void test() {
        System.out.println(myAtoi("-2147483648"));
    }


    public int myAtoi(String str) {
        long result = 0;
        str = str.trim();
        boolean fushu = false, zhegnshu = false;
        for (char ch : str.toCharArray()) {
            if (ch >= '0' && ch <= '9') {
                result = result * 10 + ch - '0';
            } else if (ch == '-') {
                if (fushu || zhegnshu) {
                    return 0;
                }
                fushu = true;
            } else if (ch == '+') {
                if (fushu || zhegnshu) {
                    return 0;
                }
                zhegnshu = true;
            } else {
                break;
            }
            if (!fushu && result > Integer.MAX_VALUE) {
                return Integer.MAX_VALUE;
            }
            if (fushu && -result < Integer.MIN_VALUE) {
                return Integer.MIN_VALUE;
            }
        }
        return (int) (fushu ? -result : result);
    }
}
