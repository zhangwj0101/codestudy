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
        System.out.println(divide(10, 3));
    }

    public static int divide(int dividend, int divisor) {

        if (divisor == 0) {
            return Integer.MAX_VALUE;
        }
        boolean flag = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
        dividend = Math.abs(dividend);
        divisor = Math.abs(divisor);
        while (divisor > 1) {
            dividend >>= 1;
            divisor >>= 1;
        }
        return flag ? dividend : -dividend;

    }
}
