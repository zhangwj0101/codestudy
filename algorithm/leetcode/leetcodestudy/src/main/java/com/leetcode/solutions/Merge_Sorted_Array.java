package com.leetcode.solutions;

import java.lang.reflect.Array;
import java.util.Arrays;

/**
 * Created by zhangwj on 16/3/4.
 */
public class Merge_Sorted_Array {

    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] temp = Arrays.copyOf(nums1, m);
        int i = 0, j = 0, k = 0;
        for (i = 0, j = 0, k = 0; i < m && j < n; ) {
            if (temp[i] <= nums2[j]) {
                nums1[k++] = temp[i];
                i++;
            } else {
                nums1[k++] = nums2[j];
                j++;
            }
        }
        while (i < m) {
            nums1[k++] = temp[i++];
        }
        while (j < n) {
            nums1[k++] = nums2[j++];
        }

    }
}
