package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/2/25.
 */
public class Permutation_Sequence_60 {

    public static void main(String[] args) {
        for (int i = 1; i <= 6; i++) {
            System.out.println(getPermutation(3, i));
        }

    }

    public static String get(char[] nums, int k, int index, int se) {
        if (k == 1) {
            return String.valueOf(nums);
        }
        if (k >= se) {
            int j = k % se == 0 ? k / se - 1 : k / se;
            char tt = nums[j + index];
            int m = j + index;
            for (; m > index; m--) {
                nums[m] = nums[m - 1];
            }
            nums[m] = tt;
            k -= j * se;
        }
        return get(nums, k, index + 1, se / (nums.length - 1 - index));

    }

    public static String getPermutation(int n, int k) {
        if (n == 1) {
            return "1";
        }
        int se = 1;
        char[] nums = new char[n];
        for (int i = 0; i < n; i++) {
            nums[i] = (char) (i + 1 + '0');
            se *= (i + 1);
        }

        return get(nums, k, 0, se / n);

    }
}
