package com.leetcode.solutions;

import org.junit.Test;

/**
 * Created by zhangwj on 16/3/8.
 */
public class Decode_Ways_91 {

    @Test
    public void test() {
        Decode_Ways_91 de = new Decode_Ways_91();
        int i = de.numDecodings("10");
        System.out.print(i);
    }


    public int numDecodings(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        int[] nums = new int[s.length() + 1];
        nums[0] = 1;
        nums[1] = s.charAt(0) != '0' ? 1 : 0;
        for (int i = 2; i <= s.length(); i++) {
            if (s.charAt(i - 1) != '0') {
                nums[i] += nums[i - 1];
            }
            int twoDigits = (s.charAt(i - 2) - '0') * 10 + s.charAt(i - 1) - '0';
            if (twoDigits >= 10 && twoDigits <= 26) {
                nums[i] += nums[i - 2];
            }
        }
        return nums[s.length()];
    }
}
