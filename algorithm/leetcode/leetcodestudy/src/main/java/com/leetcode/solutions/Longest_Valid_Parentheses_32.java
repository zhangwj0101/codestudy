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
public class Longest_Valid_Parentheses_32 {

    public static void main(String[] args) {
        String s = ")()()";
        System.out.println(longestValidParentheses1(s));
    }

    public static int longestValidParentheses(String s) {

        int len = 0, max = 0;
        Stack<Character> stacks = new Stack<>();
        for (int i = 0; i < s.length();) {
            int start = i;
            int end = start;
            len = 0;
            while (end < s.length() - 1) {
                if (s.charAt(end) == '(' && s.charAt(end + 1) == ')') {
                    len += 2;
                    end += 2;
                } else {
                    end++;
                }
            }
            i = end + 1;
            max = max > len ? max : len;
        }
        return max;
    }

    public static int longestValidParentheses1(String s) {
        int len = 0, max = 0;
        Stack<NodeCh> stacks = new Stack<>();
        int[] indes = new int[s.length()];
        for (int i = 0; i < s.length(); i++) {
            char temp = s.charAt(i);
            if (temp == '(') {
                stacks.push(new NodeCh(i, '('));
            } else {
                if (stacks.empty()) {
                    continue;
                }
                NodeCh nodeCh = stacks.pop();
                indes[nodeCh.index] = i;
            }
        }
        for (int i = 0; i < s.length(); i++) {
            int j = i;
            len = indes[j] == 0 ? 0 : indes[i] - i + 1;
            while (indes[j] != 0
                   && indes[j] + 1 < s.length()
                   && indes[indes[j] + 1] != 0) {

                j = indes[j] + 1;
                len = indes[j] - i + 1;
            }

            max = max > len ? max : len;
        }
        return max > len ? max : len;
    }

}

class NodeCh {

    int index;
    char ch;

    public NodeCh(int index, char ch) {
        this.index = index;
        this.ch = ch;
    }

}
