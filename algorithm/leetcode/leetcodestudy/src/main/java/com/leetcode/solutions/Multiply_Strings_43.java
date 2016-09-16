package com.leetcode.solutions;

import java.math.BigInteger;
import java.util.Arrays;
import java.util.Observable;

/**
 * Created by zhangwj on 16/2/23.
 */
public class Multiply_Strings_43 {
    public static void main(String[] args) {
        System.out.println(multiply3("456", "23"));
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

    public static String multiply3(String num1, String num2) {
        StringBuilder sb = new StringBuilder();

        int[] res = new int[num1.length() + num2.length() + 1];
        int left = 0, k = res.length - 1, t = 0;
        for (int i = num1.length() - 1; i >= 0; i--) {
            t = k;
            for (int j = num2.length() - 1; j >= 0; j--) {
                int temp = (num1.charAt(i) - '0') * (num2.charAt(j) - '0') + left + res[t];
                left = temp / 10;
                res[t--] = temp % 10;
            }
            if (left > 0) {
                res[t--] = left;
                left = 0;
            }
            k--;
        }
        left = 0;
        while (left < res.length && res[left] == 0) {
            left++;
        }

        while (left < res.length) {
            sb.append(res[left++]);
        }
        return sb.length() == 0 ? "0" : sb.toString();
    }
}
