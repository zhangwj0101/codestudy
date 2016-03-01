package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/1.
 */
public class Climbing_Stairs_70 {

    public static void main(String[] args) {
        Climbing_Stairs_70 s = new Climbing_Stairs_70();
        System.out.println(s.climbStairs(44));
    }

    public int get(int n, int[] table) {
        if (n <= 1) {
            return 1;
        }

        if (table[n - 1] == 0) {
            table[n - 1] = get(n - 1, table);
        }
        if (table[n - 2] == 0) {
            table[n - 2] = get(n - 2, table);
        }
        return table[n - 1] + table[n - 2];
    }

    public int climbStairs(int n) {
        int[] table = new int[n + 1];

        return get(n, table);
    }
}
