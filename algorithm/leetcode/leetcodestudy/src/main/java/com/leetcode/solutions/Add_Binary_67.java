package com.leetcode.solutions;

import java.math.BigInteger;

/**
 * Created by zhangwj on 16/3/1.
 */
public class Add_Binary_67 {

    public String addBinary(String a, String b) {

        int left = 0, i = a.length() - 1, j = b.length() - 1;
        StringBuilder result = new StringBuilder();
        int ss1 = 0;
        int ss2 = 0;
        while (true) {

            ss1 = i >= 0 ? a.charAt(i) - '0' : 0;
            ss2 = j >= 0 ? b.charAt(j) - '0' : 0;

            if (i >= 0 || j >= 0 || left != 0) {
                int temp = ss1 + ss2 + left;
                result.append((char) (temp % 2 + '0'));
                left = temp / 2;
                i--;
                j--;
            } else {
                break;
            }
        }
        return result.reverse().toString();
    }

}
