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
public class Divide_Two_Integers_29 {

    public static void main(String[] args) {

        System.out.println(divide(-2147483648, -1));
    }

    public static int divide(int dividend, int divisor) {

        boolean flag = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
        long a = Math.abs((long) dividend);
        long b = Math.abs((long) divisor);
        long c = 0, result = 0;
        while (a >= b) {
            c = b;
            for (int i = 0; a >= c; i++, c <<= 1) {
                a -= c;
                result += (1 << i);
            }
        }
        if (flag) {
            return (int) Math.min(Integer.MAX_VALUE, result);
        } else {
            return (int) Math.max(Integer.MIN_VALUE, -result);
        }

    }
}
