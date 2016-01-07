/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import java.util.Arrays;

/**
 *
 * @author zhangwj
 */
public class CountPrimes_204 {

    public int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        boolean[] a = new boolean[n];
        Arrays.fill(a, true);
        for (int i = 0; i < n; i += 2) {
            a[i] = false;
        }
        a[2] = true;
        a[1] = false;
        int t = (int) Math.sqrt(n);
        for (int i = 1; i <= t; i += 2) {
            if (!a[i]) {
                continue;
            }
            for (int j = i; j * i < n; j += 2) {
                int k = j * i;
                if (!a[k]) {
                    continue;
                }
                a[j * i] = false;
            }
        }
        int count = 0;
        for (int i = 3; i < n; i += 2) {
            if (a[i]) {
                count++;
            }
        }
        return count + 1;
    }

    public static int countPrimes1(int n) {
        if (n <= 2) {
            return 0;
        }
        boolean[] a = new boolean[n];
        Arrays.fill(a, true);
        a[1] = false;
        int t = (int) Math.sqrt(n);
        for (int i = 1; i <= t; i += 2) {
            if (!a[i]) {
                continue;
            }
            for (int j = i; j * i < n; j += 2) {
                int k = j * i;
                if (!a[k]) {
                    continue;
                }
                a[j * i] = false;
            }
        }
        int count = 0;
        for (int i = 3; i < n; i += 2) {
            if (a[i]) {
                count++;
            }
        }

        return count + 1;
    }

    /**
     * 当前最快方式
     *
     * @param n
     * @return
     */
    public int countPrimes2(int n) {
        if (n <= 2) {
            return 0;
        }
        boolean[] a = new boolean[n];
        int t = (int) Math.sqrt(n);
        a[1] = true;
        for (int i = 1; i <= t; i += 2) {
            if (a[i]) {
                continue;
            }
            for (int j = i; j * i < n; j += 2) {
                int k = j * i;
                if (a[k]) {
                    continue;
                }
                a[j * i] = true;
            }
        }
        int count = 0;
        for (int i = 3; i < n; i += 2) {
            if (!a[i]) {
                count++;
            }
        }

        return count + 1;
    }

}
