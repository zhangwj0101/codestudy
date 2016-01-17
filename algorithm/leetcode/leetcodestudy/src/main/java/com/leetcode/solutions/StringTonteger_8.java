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
public class StringTonteger_8 {

    public static void main(String[] args) {
        System.out.println(myAtoi("9223372036854775809"));
    }

    public static int myAtoi(String str) {
        String temp = str.trim();
        int i = 0;
        long result = 0L;
        if (str.length() <= 0) {
            return 0;
        }
        if (temp.charAt(0) == '+' || temp.charAt(0) == '-') {
            i = 1;
        }

        for (; i < temp.length(); i++) {
            int t = temp.charAt(i) - '0';
            if (t >= 0 && t <= 9) {
                result = result * 10 + t;
            } else {
                break;
            }
            if (result > Integer.MAX_VALUE) {
                break;
            }
        }
        if (result > Integer.MAX_VALUE && temp.charAt(0) == '-') {
            return Integer.MIN_VALUE;
        }
        if (result > Integer.MAX_VALUE) {
            return Integer.MAX_VALUE;
        }
        return (int) (temp.charAt(0) == '-' ? -result : result);
    }

    public int myAtoi1(String str) {
        String temp = str.trim();
        int i = 0;
        long result = 0L;
        if (temp.length() <= 0) {
            return 0;
        }
        if (temp.charAt(0) == '-' || temp.charAt(0) == '+') {
            i = 1;
        }
        long con = ((long) Integer.MAX_VALUE + 10);
        boolean flag = temp.charAt(0) == '-';
        for (; i < temp.length() && result <= con; i++) {
            int t = temp.charAt(i) - '0';
            if (t >= 0 && t <= 9) {
                result = result * 10 + t;
            } else {
                break;
            }
        }
        if (result > (long) Integer.MAX_VALUE) {
            return flag ? Integer.MIN_VALUE : Integer.MAX_VALUE;
        }
        return (int) (flag ? -result : result);
    }

}
