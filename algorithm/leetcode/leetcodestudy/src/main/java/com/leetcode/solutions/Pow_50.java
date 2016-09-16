package com.leetcode.solutions;

import org.junit.Test;

import java.util.Arrays;

/**
 * Created by zhangwj on 16/2/25.
 */
public class Pow_50 {

    @Test
    public void main() {

        int[] nums = {49, 38, 65};
        int[] temp = new int[nums.length];
//        System.out.println(myPow(2, -2147483648));
        mergeSort(nums, temp, 0, nums.length - 1);
        System.out.println(Arrays.toString(temp));
    }

    public static double myPow(double x, int n) {
        if (x == 1) return 1.0;
        else if (x == -1) return n % 2 == 1 ? -1.0 : 1.0;
        else if (x == 0) return 0.0;
        double res = 1.0;
        long nn = n;
        if (nn < 0)
            nn = -nn;
        while (nn != 0) {
            if ((nn & 1) == 1)
                res *= x;
            nn >>= 1;
            x *= x;
        }
        if (n > 0)
            return res;
        else return 1 / res;
    }

    public void mergeSort(int[] nums, int[] nums1, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(nums, nums1, left, mid);
            mergeSort(nums, nums1, mid + 1, right);
            merge(nums, nums1, left, mid, right);
        }
    }

    private void merge(int[] nums, int[] nums1, int left, int mid, int right) {
        int j = mid + 1, tk = left, k = left;

        for (k = left; left <= mid && j <= right; k++) {
            if (nums[left] > nums[j]) {
                nums1[k] = nums[j++];
            } else {
                nums1[k] = nums[left++];
            }
        }
        while (left <= mid) {
            nums1[k++] = nums[left++];
        }
        while (j <= right) {
            nums1[k++] = nums[j++];
        }
        while (tk <= right) {
            nums[tk] = nums1[tk];
            tk++;
        }
    }
}
