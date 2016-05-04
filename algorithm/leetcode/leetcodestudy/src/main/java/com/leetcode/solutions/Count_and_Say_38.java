/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

/**
 * @author zhangwj
 */
public class Count_and_Say_38 {

    public static void main(String[] args) {
        System.out.println(countAndSay(5));
    }

    public static String countAndSay(int n) {
        if (n < 1) {
            return null;
        }
        String[] results = new String[n];
        StringBuilder sb = new StringBuilder(1024);
        results[0] = new String("1");

        for (int i = 1; i < n; i++) {
            char[] temp = results[i - 1].toCharArray();
            sb.delete(0, sb.length());
            for (int j = 0; j < temp.length; ) {
                char t = temp[j];
                int len = 1;
                j++;
                while (j < temp.length && temp[j] == t) {
                    j++;
                    len++;
                }
                sb.append(len).append(t);
            }
            results[i] = sb.toString();
        }
        return results[n - 1];
    }
}
