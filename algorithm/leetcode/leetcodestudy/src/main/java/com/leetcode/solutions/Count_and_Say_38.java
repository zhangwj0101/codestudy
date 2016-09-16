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
public class Count_and_Say_38 {

    @Test
    public void main() {
        System.out.println(countAndSay(7));
    }

    public static String countAndSay(int n) {
        if (n < 1) {
            return null;
        }
        String[] buffer = new String[n + 1];
        buffer[1] = "1";
        StringBuilder sb = new StringBuilder();
        for (int i = 2; i <= n; i++) {
            String temp = buffer[i - 1];
            int te = 1, j = 1;
            for (; j < temp.length(); j++) {
                if (temp.charAt(j) == temp.charAt(j - 1)) {
                    te++;
                } else {
                    sb.append(te).append(temp.charAt(j - 1));
                    te = 1;
                }
            }
            sb.append(te).append(temp.charAt(j - 1));
            buffer[i] = sb.toString();
            sb.delete(0, sb.length());
        }
        return buffer[n];
    }
}
