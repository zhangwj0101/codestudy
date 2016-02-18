/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import java.util.Stack;

/**
 *
 * @author zhangwj
 */
public class Valid_Parentheses_20 {

    public static void main(String[] args) {
        System.out.println(isValid("(])}[}[}[]][}}[}{})][[(]({])])}}(])){)((){"));
    }

    public static boolean isValid(String s) {
        if (s.length() % 2 != 0) {
            return false;
        }
        Stack<Character> stack = new Stack<>();
        int left = '0';
        for (int i = 0; i < s.length(); i++) {
            left = '0';
            switch (s.charAt(i)) {
                case ')':
                    left = '(';
                    break;
                case ']':
                    left = '[';
                    break;
                case '}':
                    left = '{';
                    break;

            }
            if (stack.size() == 0 || left == '0') {
                stack.push(s.charAt(i));
                continue;
            }
            Character peek = stack.peek();
            if (peek == left) {
                stack.pop();
            } else {
                return false;
            }
        }
        return stack.size() == 0;
    }
}
