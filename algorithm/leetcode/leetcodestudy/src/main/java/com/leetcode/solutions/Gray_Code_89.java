package com.leetcode.solutions;

import java.util.*;

/**
 * Created by zhangwj on 16/3/3.
 */
public class Gray_Code_89 {

    public static void main(String[] args) {

        Gray_Code_89 g = new Gray_Code_89();
        System.out.println(g.grayCode(4));
//        System.out.println(Integer.parseInt("10000000000"));

    }

    public int get(int num, int i, int n, List<Integer> results) {
        if (i > n) {
            results.add(num);
            return num;
        }
        int t = 1 << (n - i);
        num = get(num, i + 1, n, results);
        num ^= t;
        return get(num, i + 1, n, results);
    }

    public List<Integer> grayCode(int n) {
        if (n == 0) {
            return Arrays.asList(0);
        }

        List<Integer> results = new ArrayList<>();
        get(0, 1, n, results);
        return results;
    }
}
