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
//        System.out.println(findMedianSortedArrays(nums1, nums2));
        System.out.println(findMedianSortedArrays1(nums1, nums2));
        System.out.println(findMedianSortedArrays4(nums1, nums2));
        System.out.println(findMedianSortedArrays2(nums1, nums2));
        System.out.println(findMedianSortedArrays6(nums1, nums2));
    }

    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {

        long start = System.currentTimeMillis();
        int i = 0, j = 0, k = 0;
        int[] c = new int[nums1.length + nums2.length];
        for (; i < nums1.length && j < nums2.length; ) {
            if (nums1[i] < nums2[j]) {
                c[k++] = nums1[i];
                i++;
            } else {
                c[k++] = nums2[j];
                j++;
            }
        }
        for (; i < nums1.length; i++) {
            c[k++] = nums1[i];
        }
        for (; j < nums2.length; j++) {
            c[k++] = nums2[j];
        }
        System.out.println(System.currentTimeMillis() - start);
        if (c.length % 2 == 1) {
            return c[c.length / 2];
        } else {
            return (c[c.length / 2] + c[c.length / 2 - 1]) / 2.;
        }
    }

    public static double findMedianSortedArrays1(int[] nums1, int[] nums2) {
        long start = System.currentTimeMillis();
        int i = 0, j = 0, k = 0;
        int left = 0, right = 0;
        int len = (nums1.length + nums2.length) / 2;
        while (k <= len) {
            k++;
            left = right;
            if (i < nums1.length && j < nums2.length) {
                right = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
                continue;
            }
            if (i < nums1.length) {
                right = nums1[i++];
                continue;
            }
            if (j < nums2.length) {
                right = nums2[j++];
            }
        }
        System.out.println(System.currentTimeMillis() - start);
        return (nums1.length + nums2.length) % 2 == 1 ? right : (left + right) / 2.;
    }

    public static double findMedianSortedArrays2(int[] nums1, int[] nums2) {
        long start = System.currentTimeMillis();
        int i = 0, j = 0, k = 0;
        int left = 0, right = 0;
        int len = (nums1.length + nums2.length) / 2;

        for (; i < nums1.length && j < nums2.length && k <= len; k++) {
            left = right;
            right = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
        }
        for (; k <= len && i < nums1.length; k++) {
            left = right;
            right = nums1[i++];
        }
        for (; k <= len && j < nums2.length; k++) {
            left = right;
            right = nums2[j++];
        }
        System.out.println(System.currentTimeMillis() - start);
        return (nums1.length + nums2.length) % 2 == 1 ? right : (left + right) / 2.;
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
        long start = System.currentTimeMillis();
        int m = A.length, n = B.length;
        double len = 0;
        if ((n + m) % 2 == 1) {
            len = findKthSortedArrays(A, 0, m, B, 0, n, (n + m) / 2 + 1);
        } else {
            len = (findKthSortedArrays(A, 0, m, B, 0, n, (n + m) / 2 + 1)
                    + findKthSortedArrays(A, 0, m, B, 0, n, (n + m) / 2)) / 2.0;
        }
        System.out.println(System.currentTimeMillis() - start);
        return len;
    }

    public static double findMedianSortedArrays5(int[] nums1, int[] nums2) {
//        long start = System.nanoTime();
        int i = 0, j = 0, k = 0;
        int left = 0, right = 0;
        int len = (nums1.length + nums2.length) / 2;
        int pa = len - nums1.length / 2;
        int pb = len - pa;
        int astart = 0, aend = nums1.length;
        int bstart = 0, bend = nums2.length;
        for (; astart < aend && bstart < bend; ) {
            left = right;
            if (len == 1) {
                return Math.min(nums1[astart], nums2[bstart]);
            }
            if (nums1[astart + pa] > nums2[bstart + pb]) {
                bstart += pb;
                len -= pb;
            } else if (nums1[astart + pa] < nums2[bstart + pb]) {
                astart += pa;
                len -= pa;
            } else {
                return nums1[astart + pa];
            }
            pa = len / 2;
            pb = len - pa;

        }
        return 0;
//        return (nums1.length + nums2.length) % 2 == 1 ? right : (left + right) / 2.;
    }

    public static double findMedianSortedArrays6(int[] nums1, int[] nums2) {
        long start = System.nanoTime();
        if (nums1.length == 0) {
            return singleArrayMedian(nums2);
        } else if (nums2.length == 0) {
            return singleArrayMedian(nums1);
        }
        final int k = nums1.length + nums2.length;
        int[] smaller = nums1.length <= nums2.length ? nums1 : nums2;
        int[] bigger = smaller == nums1 ? nums2 : nums1;
        int[] median = findMedian(smaller, bigger, (k - 1) / 2 + 1);
        int m1 = median[0] >= 0 ? smaller[median[0]] : bigger[median[1]];
        if (k % 2 == 1) {
            return m1;
        }
        // For even lengths, we need to find the next median.
        // It should be somewhere nearby!
        int i1 = median[0] >= 0 ? median[0] + 1 : -median[0] - 1;
        int i2 = median[1] >= 0 ? median[1] + 1 : -median[1] - 1;
        int m2;
        if (i1 == smaller.length) {
            m2 = bigger[i2];
        } else if (i2 == bigger.length) {
            m2 = smaller[i1];
        } else {
            m2 = Math.min(smaller[i1], bigger[i2]);
        }
        System.out.println(System.nanoTime() - start);
        return ((double) m1 + m2) / 2.0;
    }

    /**
     * Finds median or one of the medians. The median coordinate is given by the
     * {@code leCount} parameter which can be though of as 1-based index of the
     * median (like in the find kth element problem). The returning value
     * contains two values: first for the {@code nums1} array, second for the
     * {@code nums2} one. One of the values is a non-negative index indicating
     * where the median was found. The other one is an insertion point like in
     * binary search, that is, {@code -index - 1}. Unlike binary search,
     * however, the median may actually be present at that point too, the
     * algorithm just doesn't check that.
     *
     * @param nums1   the first array
     * @param nums2   the second array
     * @param leCount the number of the elements in the merged array that are
     *                less than or equal to the median (including itself, but not beyond)
     * @return an array of one index and one insertion point
     */
    private static int[] findMedian(int[] nums1, int[] nums2, int leCount) {
        int s1 = 0, e1 = nums1.length - 1;
        while (s1 <= e1) {
            int mid1 = (s1 + e1) / 2;
            // We have exactly mid1 + 1 elements in the first array that
            // are less than or equal to nums1[mid1] (including itself).
            // If mid1 is the median, then there must be exactly
            // leCount - (mid1 + 1) elements in the second array that
            // are less than or equal to the would-be median.
            // All subsequent elements must be greater than or equal,
            // so they can be put into the right half during the merge.
            int le2 = leCount - (mid1 + 1);
            assert le2 >= 0 && le2 <= nums2.length;
            if ((le2 == 0 || nums2[le2 - 1] <= nums1[mid1])
                    && (le2 == nums2.length || nums2[le2] >= nums1[mid1])) {
                return new int[]{mid1, -le2 - 1};
            } else if (le2 > 0 && nums2[le2 - 1] > nums1[mid1]) {
                // missed, the median must be to the right
                s1 = mid1 + 1;
            } else {
                // or to the left
                e1 = mid1 - 1;
            }
        }
        // Haven't found the median in the first array, but we now know
        // where it would be if it was there. That means we know exactly
        // how many elements less than the median are here. That gives
        // us the exact answer where the median is in the second array!
        int mid2 = leCount - s1 - 1;
        assert mid2 >= 0 && mid2 < nums2.length;
        return new int[]{-s1 - 1, mid2};
    }

    private static double singleArrayMedian(int[] nums) {
        if (nums.length % 2 == 0) {
            return ((double) nums[nums.length / 2 - 1] + nums[nums.length / 2]) / 2.0;
        } else {
            return nums[nums.length / 2];
        }
    }

    public static double findMedianSortedArrays10(int[] nums1, int[] nums2) {

        long start = System.currentTimeMillis();
        int i = 0, j = 0, k = 0;
        int[] c = new int[nums1.length + nums2.length];
        for (; i < nums1.length && j < nums2.length; ) {
            if (nums1[i] < nums2[j]) {
                c[k++] = nums1[i];
                i++;
            } else {
                c[k++] = nums2[j];
                j++;
            }
        }
        for (; i < nums1.length; i++) {
            c[k++] = nums1[i];
        }
        for (; j < nums2.length; j++) {
            c[k++] = nums2[j];
        }
        System.out.println(System.currentTimeMillis() - start);
        if (c.length % 2 == 1) {
            return c[c.length / 2];
        } else {
            return (c[c.length / 2] + c[c.length / 2 - 1]) / 2.;
        }
    }

    public static int get(int[] num1, int[] num2, int k) {

        int as = 0, bs = 0;
        int pa = 0, pb = k - pa;
        int ae = num1.length, be = num2.length;
        int cur = 0;
        while (k > 1) {
            pa = Math.min(k / 2, (ae - as) / 2 > (be - bs) / 2 ? (be - bs) / 2 : (ae - as) / 2);
            pb = k - pa;
            if (num1[as + pa - 1] > num2[bs + pb - 1]) {
                bs = bs + pb;
                ae = as + pa;
                k -= pb;
            } else if (num1[as + pa - 1] < num2[bs + pb - 1]) {
                as = as + pa;
                be = bs + pb;
                k -= pa;
            } else {
                return num1[pa - 1];
            }

        }
        return Math.min(num1[as], num2[bs]);
    }
}
