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
public class ZigZagConversion_6 {

    @Test
    public void main() {
        System.out.println(convert("Aas", 2));
    }

    public String convert(String s, int numRows) {
        if (numRows == 1 || s.length() == 1) {
            return s;
        }
        StringBuilder[] sb = new StringBuilder[numRows];
        for (int i = 0; i < numRows; i++) {
            sb[i] = new StringBuilder();
        }
        int k = 0;
        while (k < s.length()) {
            for (int i = 0; i < numRows && k < s.length(); i++, k++) {
                sb[i].append(s.charAt(k));
            }
            for (int i = numRows - 2; i > 0 && k < s.length(); i--, k++) {
                sb[i].append(s.charAt(k));
            }
        }
        StringBuilder res = new StringBuilder();
        for (StringBuilder te : sb) {
            res.append(te);
        }
        return res.toString();
    }
}
