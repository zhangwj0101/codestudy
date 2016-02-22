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
public class Valid_Sudoku_36 {

    public boolean checkValid(int[] vec, int val) {
        if (val < 0) {
            return true;
        }
        if (vec[val] == 1) {
            return false;
        }
        vec[val] = 1;
        return true;
    }

    public boolean isValidSudoku(char[][] board) {
        int[] rowValid = new int[board.length + 1];
        int[][] columnValid = new int[board.length][board.length + 1];
        int[][] subBoxValid = new int[board.length][board.length + 1];

        for (int i = 0; i < board.length; i++) {
            Arrays.fill(rowValid, 0);
            for (int j = 0; j < board.length; j++) {
                if (!checkValid(rowValid, board[i][j] - '0')
                    || !checkValid(columnValid[j], board[i][j] - '0')
                    || !checkValid(subBoxValid[i / 3 * 3 + j / 3], board[i][j] - '0')) {
                    return false;
                }
            }
        }
        return true;
    }

}
