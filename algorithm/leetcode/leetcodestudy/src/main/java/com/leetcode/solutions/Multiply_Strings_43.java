package com.leetcode.solutions;

import java.math.BigInteger;
import java.util.Arrays;

/**
 * Created by zhangwj on 16/2/23.
 */
public class Multiply_Strings_43 {
    public static void main(String[] args) {
        System.out.println(multiply("123", "456"));
    }

    public static String multiply(String num1, String num2) {

        String s1 = num1.length() > num2.length() ? num1 : num2;
        String s2 = num1.length() > num2.length() ? num2 : num1;

        String num = new StringBuilder(s2).reverse().toString();
        StringBuilder sb = new StringBuilder(s1).reverse();
        char[] result = new char[num1.length() + num2.length() + 1];
        Arrays.fill(result, '0');
        int left = 0, k = 0;
        for (int i = 0; i < num.length(); i++) {
            if (i > 0) {
                sb.insert(0, '0');
            }
            k = 0;
            left = 0;
            for (int j = 0; j < sb.length(); j++) {
                int temp = (num.charAt(i) - '0') * (sb.charAt(j) - '0') + left + result[j] - '0';
                left = temp / 10;
                temp %= 10;
                result[k++] = (char) (temp + '0');
            }
            result[k++] = (char) (left + '0');
        }

        while (k > 0 && result[k] == '0') {
            k--;
        }
        return new StringBuilder(new String(result, 0, k + 1)).reverse().toString();
    }

    public String multiply1(String num1, String num2) {
        if (num1 == null || num2 == null) {
            return null;
        }

        int len1 = num1.length();
        int len2 = num2.length();
        int[] sum = new int[len1 + len2];

        // sum all of the mutiply result.
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                sum[i + j] += (num1.charAt(len1 - 1 - i) - '0') * (num2.charAt(len2 - 1 - j) - '0');
            }
        }

        int carry = 0;
        for (int i = 0; i < len1 + len2; i++) {
            sum[i] = sum[i] + carry;
            carry = sum[i] / 10;
            sum[i] %= 10;
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < len1 + len2; i++) {
            sb.insert(0, sum[i] + "");
        }

        while (sb.charAt(0) == '0' && sb.length() != 1) {
            sb.deleteCharAt(0);
        }
        return sb.toString();
    }
}
