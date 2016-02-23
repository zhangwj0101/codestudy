/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

/**
 * @author zhangwj
 */
public class Trapping_Rain_Water_42 {

    public static void main(String[] args) {
        int[] heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        System.out.println(trap1(heights));
    }

    public static int trap(int[] height) {
        int[] maxv = new int[height.length];
        int res = 0;
        int max = 0;
        for (int i = height.length - 1; i >= 0; i--) {
            maxv[i] = max;
            max = height[i] > max ? height[i] : max;
        }
        max = 0;
        for (int i = 0; i < height.length; i++) {
            int conhei = Math.min(max, maxv[i]);
            if (conhei > height[i]) {
                res += conhei - height[i];
            }
            max = max < height[i] ? height[i] : max;
        }
        return res;
    }

    public static int trap1(int[] height) {

        int res = 0;
        int maxindex = 0, max = 0;
        for (int i = 0; i < height.length; i++) {
            if (height[i] > max) {
                max = height[i];
                maxindex = i;
            }
        }
        for (int i = 0, left = 0; i < maxindex; i++) {
            if (height[i] > left) {
                left = height[i];
            } else {
                res += left - height[i];
            }
        }
        for (int i = height.length - 1, right = 0; i > maxindex; i--) {
            if (height[i] > right) {
                right = height[i];
            } else {
                res += right - height[i];
            }
        }
        return res;
    }
}
