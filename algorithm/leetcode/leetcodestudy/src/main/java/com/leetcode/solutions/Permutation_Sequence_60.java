package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/2/25.
 */
public class Permutation_Sequence_60 {

    public static void main(String[] args) {
        System.out.println(getPermutation(3, 4));
    }

    public static String get(int[] nums, int k, int index, int se) {
        if (k == 1) {
            return String.valueOf(nums);
        }
        if (k >= se) {
            int j = k % se == 0 ? k / se - 1 : k / se;
            int tt = nums[j + index];
            int m = j + index;
            for (; m > index; m--) {
                nums[m] = nums[m - 1];
            }
            nums[m] = tt;
            return get(nums, k - j * se, index + 1, se / (nums.length - 1 - index));
        } else {
            get(nums, k, index + 1, se);
        }
        return null;
    }

    public static String getPermutation(int n, int k) {
        if (n == 1) {
            return "1";
        }
        int se = 1;
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
            se *= (i + 1);
        }

        get(nums, k, 0, se / n);

        return null;
    }
}