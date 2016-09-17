/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import java.util.Arrays;

/**
 * @author zhangwj
 */
public class MedianTwoSortedArrays_4 {

    public static void main(String[] args) {

        int m1 = 1000000;
        int m2 = 100000;
        int[] nums1 = new int[m1];
        int[] nums2 = new int[m2];
        for (int i = 0; i < m1; i++) {
            nums1[i] = (int) (Math.random() * m1) % m1;
        }
        for (int i = 0; i < m2; i++) {
            nums2[i] = (int) (Math.random() * m2) % m2;
        }
        Arrays.sort(nums2);
        Arrays.sort(nums1);
        System.out.println(findMedianSortedArrays4(nums1, nums2));
    }

    private static double findKthSortedArrays(int A[], int astart, int aend,
                                              int B[], int bstart, int bend, int k) {
        int m = aend - astart, n = bend - bstart;
        if (m < n) {
            return findKthSortedArrays(B, bstart, bend, A, astart, aend, k);
        }
        if (n == 0) {
            return A[astart + k - 1];
        }
        if (k == 1) {
            return Math.min(A[astart], B[bstart]);
        }

        int pb = Math.min(k / 2, n), pa = k - pb;

        if (A[astart + pa - 1] > B[bstart + pb - 1]) {
            return findKthSortedArrays(A, astart, aend, B, bstart + pb, bend, k - pb);
        } else if (A[astart + pa - 1] < B[bstart + pb - 1]) {
            return findKthSortedArrays(A, astart + pa, aend, B, bstart, bend, k - pa);
        } else {

            return A[astart + pa - 1];
        }
    }

    /**
     * 每次减少指定量的数据，递归减少的方式
     *
     * @param A
     * @param B
     * @return
     */
    public static double findMedianSortedArrays4(int A[], int B[]) {
        int m = A.length, n = B.length;
        double len = 0;
        if ((n + m) % 2 == 1) {
            len = findKthSortedArrays(A, 0, m, B, 0, n, (n + m) / 2 + 1);
        } else {
            len = (findKthSortedArrays(A, 0, m, B, 0, n, (n + m) / 2 + 1)
                    + findKthSortedArrays(A, 0, m, B, 0, n, (n + m) / 2)) / 2.0;
        }
        return len;
    }
}
