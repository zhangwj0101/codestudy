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
public class ReverseInteger_7 {

    @Test
    public void test() {
    }

    public int reverse(int x) {
        long result = 0;
        boolean flag = x < 0;
        x = Math.abs(x);
        while (x > 0) {
            result = result * 10 + x % 10;
            x /= 10;
        }
        if (!flag && result > Integer.MAX_VALUE) {
            return 0;
        }
        if (flag && -result < Integer.MIN_VALUE) {
            return 0;
        }
        return (int) (flag ? -result : result);
    }
}
