/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

/**
 * @author zhangwj
 */
public class ReverseInteger_7 {

    public static void main(String[] args) {
        //2147483647
//        System.out.println(reverse2(1463847412));
//        System.out.println(Integer.reverse(123));
    }

    public static int reverse(int x) {
        String s = String.valueOf(Math.abs(x));
        char[] chs = s.toCharArray();
        for (int start = 0, end = chs.length - 1; start < end; start++, end--) {
            char t = chs[start];
            chs[start] = chs[end];
            chs[end] = t;
        }
        int result = 0;
        char[] valueOf = String.valueOf(Integer.MAX_VALUE).toCharArray();
        if (chs.length > valueOf.length) {
            return 0;
        }

        for (int i = 0, j = 0; (chs.length == valueOf.length) && i < chs.length && j < valueOf.length; i++, j++) {
            if (chs[i] < valueOf[j]) {
                break;
            }
            if (chs[i] > valueOf[j]) {
                return 0;
            }
        }

        for (int i = 0; i < chs.length; i++) {
            result = result * 10 + (chs[i] - '0');
        }
        return x > 0 ? result : -result;
    }

    public int reverse1(int x) {
        String s = String.valueOf(Math.abs(x));
        char[] chs = s.toCharArray();
        for (int start = 0, end = chs.length - 1; start < end; start++, end--) {
            char t = chs[start];
            chs[start] = chs[end];
            chs[end] = t;
        }
        int result = 0;

        for (int i = 0; i < chs.length; i++) {
            if ((Integer.MAX_VALUE - (chs[i] - '0')) / 10 < result) {
                return 0;
            }
            result = result * 10 + (chs[i] - '0');

        }
        return x > 0 ? result : -result;
    }

    public static int reverse2(int x) {
        int result = 0;
        int temp = Math.abs(x);

        while (temp > 0) {
            if (result > (Integer.MAX_VALUE - temp) / 10) {
                return 0;
            }
            result = result * 10 + temp % 10;
            temp /= 10;
        }
        return x > 0 ? result : -result;
    }

    public int reverse4(int x) {
        long ret = 0;
        while (x != 0) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        if (ret > Integer.MAX_VALUE || ret < Integer.MIN_VALUE) {
            return 0;
        }
        return (int) ret;
    }
}
