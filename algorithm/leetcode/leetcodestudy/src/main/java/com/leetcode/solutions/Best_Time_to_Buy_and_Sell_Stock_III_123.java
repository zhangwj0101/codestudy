package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/15.
 */
public class Best_Time_to_Buy_and_Sell_Stock_III_123 {
    public int maxProfit(int[] prices) {

        if (prices == null || prices.length == 0) {
            return 0;
        }
        int len = prices.length;
        int[] left = new int[len];
        int[] right = new int[len];

        int min = prices[0];
        left[0] = 0;
        for (int i = 1; i < len; i++) {
            min = Math.min(min, prices[i]);
            left[i] = Math.max(left[i - 1], prices[i] - min);
        }

        int max = prices[len - 1];
        right[len - 1] = 0;
        for (int i = len - 2; i >= 0; i--) {
            max = Math.max(max, prices[i]);
            right[i] = Math.max(right[i + 1], max - prices[i]);
        }

        int rst = 0;
        for (int i = 0; i < len; i++) {
            rst = Math.max(rst, left[i] + right[i]);
        }

        return rst;
    }

    public int maxProfit1(int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0;
        }

        int ret = 0;

        int len = prices.length;
        int[] leftProfile = new int[len];

        int min = prices[0];
        leftProfile[0] = 0;
        for (int i = 1; i < len; i++) {
            min = Math.min(min, prices[i]);
            leftProfile[i] = Math.max(leftProfile[i - 1], prices[i] - min);
        }

        int max = Integer.MIN_VALUE;
        int profile = 0;
        for (int i = len - 1; i >= 0; i--) {
            max = Math.max(max, prices[i]);
            profile = Math.max(profile, max - prices[i]);

            // sum the left profit and the right profit.
            ret = Math.max(ret, profile + leftProfile[i]);
        }

        return ret;
    }
}
