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
public class IntegertoRoman_12 {

    public static void main(String[] args) {
        System.out.println(intToRoman1(14));
    }

    public static String intToRoman(int num) {
        int[] token = {1, 5, 10, 50, 100, 500, 1000};
        char[] chtoken = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        String[] nums = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
        StringBuilder sb = new StringBuilder();
        int i = token.length - 1;
        while (num > 0 && i >= 0) {
            if (num >= 900 && num < 1000) {
                sb.append("CM");
                num -= 900;
            } else if (num >= 400 && num < 500) {
                sb.append("CD");
                num -= 400;
            } else if (num >= 90 && num < 100) {
                sb.append("XC");
                num -= 90;
            } else if (num >= 40 && num < 50) {
                sb.append("XL");
                num -= 40;
            } else if (num <= 10) {
                sb.append(nums[num - 1]);
                num = 0;
            } else {
                int temp = num / token[i];
                for (int j = 0; j < temp; j++) {
                    sb.append(chtoken[i]);
                }
                num -= token[i] * temp;
                i--;
            }
        }
        return sb.toString();
    }

    public static String intToRoman1(int num) {
        int[] token = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        String[] lmtoken = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        StringBuilder sb = new StringBuilder();
        int i = token.length - 1;
        while (num > 0 && i >= 0) {
            int temp = num / token[i];
            for (int j = 0; j < temp; j++) {
                sb.append(lmtoken[i]);
            }
            num -= token[i] * temp;
            i--;
        }
        return sb.toString();
    }
}
