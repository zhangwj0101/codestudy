package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/1.
 */
public class Climbing_Stairs_70 {

    public static void main(String[] args) {
        Climbing_Stairs_70 s = new Climbing_Stairs_70();
        System.out.println(s.climbStairs(3));
    }

    public int get(int n) {
        if (n <= 0) {
            return 0;
        }
    
        return 2 + get(n - 1) + get(n - 2);
    }

    public int climbStairs(int n) {

        return get(n);
    }
}
