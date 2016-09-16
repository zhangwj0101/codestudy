package com.leetcode.solutions;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by zhangwj on 16/2/25.
 */
public class N_Queens_II_52 {

    @Test
    public void main() {
        int lists = totalNQueens(4);
        System.out.println(lists);
    }

    public void get(List<List<String>> results, char[][] queen, int i) {
        if (i >= queen.length) {
            List<String> rs = new ArrayList<>();
            for (int t = 0; t < queen.length; t++) {
                rs.add(String.valueOf(queen[t]));
            }
            results.add(rs);
            return;
        }

        for (int t = 0; t < queen.length; t++) {
            if (check(queen, i, t)) {
                queen[i][t] = 'Q';
                get(results, queen, i + 1);
                queen[i][t] = '.';
            }
        }
    }

    public boolean check(char[][] queen, int i, int j) {

        for (int k = j - 1; k >= 0; k--) {
            if (queen[i][k] == 'Q') {
                return false;
            }
        }
        for (int k = i - 1; k >= 0; k--) {
            if (queen[k][j] == 'Q') {
                return false;
            }
        }
        for (int k = i - 1, t = j - 1; k >= 0 && t >= 0; k--, t--) {
            if (queen[k][t] == 'Q') {
                return false;
            }
        }
        for (int k = i - 1, t = j + 1; k >= 0 && t < queen.length; k--, t++) {
            if (queen[k][t] == 'Q') {
                return false;
            }
        }
        return true;
    }

    public int totalNQueens(int n) {
        List<List<String>> results = new ArrayList<>();
        char[][] queen = new char[n][n];
        for (int t = 0; t < queen.length; t++) {
            Arrays.fill(queen[t], '.');
        }
        get(results, queen, 0);
        return results.size();
    }


}
