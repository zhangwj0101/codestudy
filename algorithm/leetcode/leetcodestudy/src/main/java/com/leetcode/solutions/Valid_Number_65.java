package com.leetcode.solutions;

import org.junit.Test;

import java.math.BigDecimal;

/**
 * Created by zhangwj on 16/2/29.
 */
public class Valid_Number_65 {

    @Test
    public void main() {

        String s = "1 a";
        isNumber(s);
    }


    public boolean isNumber(String s) {
        if (s == null) {
            return false;
        }

        s = s.trim();
        boolean num = false;
        boolean dot = false;
        boolean exp = false;

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch >= '0' && ch <= '9') {
                num = true;
            } else if (ch == '.') {
                if (dot || exp) {
                    return false;
                }
                dot = true;
            } else if (ch == 'e') {
                if (exp || !num) {
                    return false;
                }
                exp = true;
                num = false;
            } else if (ch == '+' || ch == '-') {
                if (i != 0 && s.charAt(i - 1) != 'e') {
                    return false;
                }
            } else {
                return false;
            }
        }
        return num;
    }
}
