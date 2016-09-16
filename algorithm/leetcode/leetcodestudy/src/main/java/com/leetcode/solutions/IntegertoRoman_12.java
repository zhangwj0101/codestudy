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
public class IntegertoRoman_12 {


    @Test
    public void test() {
        System.out.println(intToRoman1(14));
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
