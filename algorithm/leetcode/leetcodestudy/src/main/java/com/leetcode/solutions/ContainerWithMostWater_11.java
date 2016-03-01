/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import java.util.Arrays;
import java.util.Comparator;

/**
 * @author zhangwj
 */
public class ContainerWithMostWater_11 {

    public static void main(String[] args) {
        int[] a = {1, 2, 3};
        System.out.println(maxArea(a));
    }

    public static int maxArea(int[] height) {
        int res = 0;
        int n = height.length;
        Node[] vec = new Node[n];
        if (n <= 1) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            vec[i] = new Node(height[i], i);
        }
        Arrays.sort(vec, new Comparator<Node>() {

            @Override
            public int compare(Node o1, Node o2) {
                return o1.height - o2.height;
            }

        });

        int start = vec[n - 1].index, end = start;
        for (int i = n - 2; i >= 0; i--) {
            start = Math.min(start, vec[i].index);
            end = Math.max(end, vec[i].index);
            res = Math.max(res, Math.max(vec[i].height * (vec[i].index - start), vec[i].height * (end - vec[i].index)));
        }
        return res;
    }

    public static int maxArea1(int[] height) {
        int lpoint = 0, rpoint = height.length - 1;
        int area = 0;
        while (lpoint < rpoint) {
            area = Math.max(area, Math.min(height[lpoint], height[rpoint])
                    * (rpoint - lpoint));
            if (height[lpoint] > height[rpoint]) {
                rpoint--;
            } else {
                lpoint++;
            }
        }
        return area;
    }

}

class Node {

    int height;
    int index;

    public Node(int height, int index) {
        this.height = height;
        this.index = index;
    }

    public Node() {
    }

}
