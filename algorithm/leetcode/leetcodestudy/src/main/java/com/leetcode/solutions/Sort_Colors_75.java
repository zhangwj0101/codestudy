package com.leetcode.solutions;

import java.util.Arrays;

/**
 * Created by zhangwj on 16/3/2.
 */
public class Sort_Colors_75 {

    public void sortColors(int[] nums) {
        Arrays.sort(nums);
    }

    public void sortColors1(int[] A) {
        if (A == null || A.length == 0) {
            return;
        }

        int len = A.length - 1;
        int left = 0;
        int right = len;

        int cur = 0;
        while (cur <= right) {
            if (A[cur] == 2) {
                // 换到右边，换过来的有可能是0，也有可能是1，所以cur要停留

                swap(A, cur, right);
                right--;
            } else if (A[cur] == 0) {
                // 从左边换过来的只可能是1，所以可以直接cur++
                // 因为所有的2全部换到右边去了。

                swap(A, cur, left);
                left++;
                cur++;
            } else {
                cur++;
            }
        }
    }

    public void swap(int[] A, int n1, int n2) {
        int tmp = A[n1];
        A[n1] = A[n2];
        A[n2] = tmp;
    }
}
