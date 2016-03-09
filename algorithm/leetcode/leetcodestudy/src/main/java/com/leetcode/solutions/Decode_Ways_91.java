package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/8.
 */
public class Decode_Ways_91 {

    public static void main(String[] args) {
        Decode_Ways_91 de = new Decode_Ways_91();
        int i = de.numDecodings("10");
        System.out.print(i);
    }


    public int get(String s, int i, int[] weights) {
        while (i < s.length() && s.charAt(i) == '0') {
            i++;
        }
        if (i >= s.length() - 1) {
            return 1;
        }

        if (weights[i + 1] == 0) {
            weights[i + 1] = get(s, i + 1, weights);
        }
        int s2 = (s.charAt(i) - '0') * 10 + s.charAt(i + 1) - '0';

        if (weights[i + 2] == 0) {
            weights[i + 2] = s2 > 26 ? 0 : get(s, i + 2, weights);
        }
        return weights[i + 1] + weights[i + 2];
    }

    public int numDecodings(String s) {
        if (s.length() < 1) {
            return 0;
        }
        if (s.charAt(s.length() - 1) == '0') {
            s = s.substring(0, s.length() - 1);
        }
        int[] nums = new int[s.length() + 1];
        return get(s, 0, nums);
    }
}
