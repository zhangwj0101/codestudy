package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/5.
 */
public class Edit_Distance_72 {

    public static void main(String[] args) {
        Edit_Distance_72 ed = new Edit_Distance_72();
        String s1 = "a";
        String s2 = "w";
        System.out.println(ed.minDistance(s1, s2));
    }

    /*
     动态规划算法解决
     */
    public int minDistance(String word1, String word2) {
        if (word1.length() == 0 || word2.length() == 0) {
            return word1.length() == 0 ? word2.length() : word1.length();
        }
        int[][] weights = new int[word1.length() + 1][word2.length() + 1];

        for (int j = 0; j <= word2.length(); j++) {
            weights[0][j] = j;
        }
        for (int i = 0; i <= word1.length(); i++) {
            weights[i][0] = i;
        }
        for (int i = 1; i <= word1.length(); i++) {
            for (int j = 1; j <= word2.length(); j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    weights[i][j] = weights[i - 1][j - 1];
                } else {
                    weights[i][j] = Math.min(weights[i - 1][j - 1]
                            , Math.min(weights[i - 1][j], weights[i][j - 1])) + 1;
                }
            }
        }
        return weights[word1.length()][word2.length()];
    }
}
