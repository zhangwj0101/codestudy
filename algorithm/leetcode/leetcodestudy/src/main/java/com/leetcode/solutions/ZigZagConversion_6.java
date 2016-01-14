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
public class ZigZagConversion_6 {

    public static void main(String[] args) {
        System.out.println(convert("ABCDEFGHIJKLMN", 4));
    }

    public static String convert(String s, int numRows) {
        int sep = 2 * numRows - 2;
        if (numRows == 1 || s.length() == 1 || s.length() < numRows) {
            return s;
        }
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < numRows; i++) {
            int t = 2 * (numRows - 1 - i);
            builder.append(s.charAt(i));
            int left = t;
            int right = sep;
            while (i + left < s.length()) {
                if (left != 0) {
                    builder.append(s.charAt(i + left));
                    if (left % sep != right % sep && i + right < s.length()) {
                        builder.append(s.charAt(i + right));
                    }
                }
                left += sep;
                right += sep;
            }
        }

        return builder.toString();
    }

    public class Solution {

        public String convert1(String s, int nRows) {
            if (nRows == 1) {
                return s;
            }
            int step = nRows * 2 - 2, len = s.length();
            String ret = "";
            // first row
            for (int i = 0; i < len; i += step) {
                ret += s.charAt(i);
            }
            for (int i = 1; i < nRows - 1; i++) {
                for (int j = i; j < len; j += step) {
                    ret += s.charAt(j);
                    if (j + (step - i * 2) < len) {
                        ret += s.charAt(j + (step - i * 2));
                    }
                }
            }
            // last row
            for (int i = nRows - 1; i < len; i += step) {
                ret += s.charAt(i);
            }
            return ret;
        }
    }

}
