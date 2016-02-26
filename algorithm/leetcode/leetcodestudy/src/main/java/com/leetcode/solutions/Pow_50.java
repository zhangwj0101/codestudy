package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/2/25.
 */
public class Pow_50 {
    public static void main(String[] args) {
        System.out.println(myPow(0.01, -2147483647));
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

}
