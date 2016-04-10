package com.leetcode.solutions;

import java.util.Stack;

/**
 * Created by zhangwj on 16/3/9.
 */
public class Largest_Rectangle_in_Histogram_84 {
    public int largestRectangleArea(int[] height) {
        if (height == null || height.length == 0) {
            return 0;
        }

        Stack<Integer> stack = new Stack<Integer>();
        int max = 0;
        for (int i = 0; i <= height.length; i++) {
            int curt = (i == height.length) ? -1 : height[i];
            while (!stack.isEmpty() && curt <= height[stack.peek()]) {
                int h = height[stack.pop()];
                int w = stack.isEmpty() ? i : i - stack.peek() - 1;
                max = Math.max(max, h * w);
            }
            stack.push(i);
        }

        return max;

    }

    public int largestRectangleArea1(int[] h) {
        Stack<Integer> stacks = new Stack<>();
        int max = 0, i = 0;
        while (i <= h.length) {
            if (stacks.empty() || i < h.length && h[i] >= h[stacks.peek()]) {
                stacks.push(i);
                i++;
            } else {
                int temp = h[stacks.pop()];
                int cur = stacks.isEmpty() ? i : i - stacks.peek() - 1;
                max = Math.max(max, temp * cur);
            }
        }
        return max;
    }
}
