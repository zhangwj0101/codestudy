package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/15.
 */
public class Best_Time_to_Buy_and_Sell_Stock_II_122 {
    public int maxProfit(int[] prices) {
        int maxProfit = 0;

        int len = prices.length;
        for (int i = 1; i < len; i++) {
            int dif = prices[i] - prices[i - 1];

            if (dif > 0) {
                maxProfit += dif;
            }
        }

        return maxProfit;
    }

}
