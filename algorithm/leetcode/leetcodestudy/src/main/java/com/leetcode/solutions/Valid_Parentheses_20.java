/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import org.junit.Test;

import java.util.Stack;

/**
 * @author zhangwj
 */
public class Valid_Parentheses_20 {


    @Test
    public void test() {
        System.out.println(isValid("()"));
    }


    public static boolean isValid(String s) {

        if (s == null) {
            return false;
        }
        Stack<Character> stacks = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == '(' || ch == '[' || ch == '{') {
                stacks.push(s.charAt(i));
            } else {
                if (stacks.empty()) {
                    return false;
                }
                Character pop = stacks.pop();
                boolean flag = (ch == ')' && pop == '(')
                        || (ch == ']' && pop == '[')
                        || (ch == '}' && pop == '{');
                if (!flag) {
                    return false;
                }
            }
        }
        return stacks.isEmpty();
    }
}
