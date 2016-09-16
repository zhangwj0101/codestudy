/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import java.util.Arrays;

/**
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

    public boolean isValidSudoku1(char[][] board) {

        return isValid(board, 1);
    }

    public boolean isValid(char[][] board, int index) {

        if (index > 80) {
            return true;
        }
        int x = (index - 1) / 9;
        int y = (index - 1) % 9;
        if (board[x][y] != '.' && !check(board, x, y)) {
            return false;
        }

        return isValid(board, index + 1);
    }

    public static boolean check(char[][] board, int x, int y) {

        int[] table = new int[board.length + 1];
        //行
        for (int t = 0; t < board.length; t++) {
            if (board[t][y] != '.' && ++table[board[t][y] - '0'] >= 2) {
                return false;
            }
        }
        Arrays.fill(table, 0);
        //列
        for (int t = 0; t < board[0].length; t++) {
            if (board[x][t] != '.' && ++table[board[x][t] - '0'] >= 2) {
                return false;
            }
        }
        int tx = x, ty = y;

        while (tx % 3 != 0) {
            tx--;
        }
        while (ty % 3 != 0) {
            ty--;
        }

        Arrays.fill(table, 0);
        //小方格
        for (int i = tx; i <= tx + 2; i++) {
            for (int j = ty; j <= ty + 2; j++) {
                if (board[i][j] != '.' && ++table[board[i][j] - '0'] >= 2) {
                    return false;
                }
            }
        }
        return true;
    }
}
