package com.leetcode.solutions;

import java.util.LinkedList;

/**
 * Created by zhangwj on 16/2/25.
 */
public class Permutation_Sequence_60 {

    public static void main(String[] args) {
        System.out.println(getPermutation1(3, 3));
        for (int i = 1; i <= 6; i++) {
            System.out.println(getPermutation1(3, i));
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

    public static String getPermutation1(int n, int k) {
        // 1:17 -> 1:43
        LinkedList<Character> digits = new LinkedList<Character>();

        // bug 2: should only add n elements.
        for (char i = '1'; i <= '0' + n; i++) {
            digits.add(i);
        }

        // The index start from 0;
        k--;
        StringBuilder sb = new StringBuilder();

        int sum = 1;
        // n!
        for (int i = 1; i <= n; i++) {
            sum *= i;
        }

        for (int i = n; i >= 1; i--) {
            sum /= i;
            int digitIndex = k / sum;
            k = k % sum;

            //Line 25: error: cannot find symbol: method digits(int)
            sb.append(digits.get(digitIndex));

            // remove the used digit.
            digits.remove(digitIndex);
        }

        return sb.toString();
    }
}
