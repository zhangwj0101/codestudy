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
