package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/1.
 */
public class Sqrt_x_68 {

    public static void main(String[] args) {
        Sqrt_x_68 s = new Sqrt_x_68();
        System.out.println(s.mySqrt(2));
    }

    public int mySqrt(int x) {

        double tn = x;
        double liasttn = Double.MAX_VALUE;
        while (Math.abs(liasttn - tn) > 0.0001) {
            liasttn = tn;
            tn = (tn + x / tn) / 2;
        }
        return (int) tn;
    }
}
