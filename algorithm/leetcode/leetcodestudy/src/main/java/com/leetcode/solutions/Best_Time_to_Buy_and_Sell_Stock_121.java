package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/15.
 */
public class Best_Time_to_Buy_and_Sell_Stock_121 {
    public int maxProfit(int[] prices) {
        int max = 0;
        int min = Integer.MAX_VALUE;
        for (int i : prices) {
            min = Math.min(min, i);
            max = Math.max(max, i - min);
        }
        return max;
    }
}
