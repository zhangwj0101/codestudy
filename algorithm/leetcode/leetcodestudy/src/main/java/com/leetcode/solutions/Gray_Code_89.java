package com.leetcode.solutions;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by zhangwj on 16/3/3.
 */
public class Gray_Code_89 {

    @Test
    public void test() {

        System.out.println(grayCode2(1));

    }

    public List<Integer> grayCode(int n) {
        List<Integer> results = new ArrayList<>();
        results.add(0);
        if (n > 0) {
            results.add(1);
        }
        int mask = 1;
        for (int i = 2; i <= n; i++) {
            mask <<= 1;
            for (int j = results.size() - 1; j >= 0; j--) {
                int t = results.get(j).intValue();
                results.add(t | mask);
            }
        }
        return results;
    }

    public List<Integer> grayCode2(int n) {
        if (n == 0) {
            return Arrays.asList(0);
        }
        List<Integer> results = new ArrayList<>();
        List<Integer> res = grayCode2(n - 1);
        results.addAll(res);
        int mask = 1 << (n - 1);
        for (int j = res.size() - 1; j >= 0; j--) {
            int t = res.get(j).intValue();
            results.add(t | mask);
        }
        return results;
    }
}
