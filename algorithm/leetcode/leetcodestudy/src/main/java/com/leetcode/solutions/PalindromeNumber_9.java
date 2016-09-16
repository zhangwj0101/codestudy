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
public class PalindromeNumber_9 {

    @Test
    public void test() {
        System.out.println(isPalindrome(12321));
    }

    public boolean isPalindrome(int x) {

        char[] temp = String.valueOf(x).toCharArray();
        for (int i = 0, end = temp.length - 1; i < end; i++, end--) {
            if (temp[i] != temp[end]) {
                return false;
            }
        }
        return true;
    }

    public boolean isPalindrome1(int x) {
        int temp = x;
        int result = 0;
        while (temp > 0) {
            result = result * 10 + temp % 10;
            temp /= 10;
        }
        return x == result;
    }

}
