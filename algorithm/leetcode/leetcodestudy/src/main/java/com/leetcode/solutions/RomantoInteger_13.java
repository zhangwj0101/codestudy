/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import java.util.HashMap;
import java.util.Map;

/**
 * @author zhangwj
 */
public class RomantoInteger_13 {

    public static void main(String[] args) {
        System.out.println(romanToInt("MMMCMXCIX"));
    }

    public static int romanToInt(String s) {

        int sum = 0;
        int last = 0;
        int value = 0;
        for (char temp : s.toCharArray()) {
            switch (temp) {
                case 'I':
                    value = 1;
                    break;
                case 'V':
                    value = 5;
                    break;
                case 'X':
                    value = 10;
                    break;
                case 'L':
                    value = 50;
                    break;
                case 'C':
                    value = 100;
                    break;
                case 'D':
                    value = 500;
                    break;
                case 'M':
                    value = 1000;
                    break;
            }

            if (last < value) {
                sum -= last * 2;
            }
            sum += value;
            last = value;
        }
        return sum;

    }
}
