/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import org.junit.Test;

import java.util.Arrays;

/**
 * @author zhangwj
 */
public class Sudoku_Solver_37 {

    int[][] rowValid;
    int[][] columnValid;
    int[][] subBox;


    public void solveSudoku(char[][] board) {
        rowValid = new int[board.length][board.length + 1];
        columnValid = new int[board.length][board.length + 1];
        subBox = new int[board.length + 1][board.length + 1];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    fill(i, j, board[i][j] - '0');
                }
            }
        }

        solve(board, 0);
    }

    public boolean solve(char[][] board, int index) {
        if (index > 80) {
            return true;
        }
        int row = index / 9,
                col = index - 9 * row;
        if (board[row][col] != '.') {
            return solve(board, index + 1);
        }
        for (int val = '1'; val <= '9'; val++) {
            if (isValid(row, col, val - '0')) {
                board[row][col] = (char) val;
                fill(row, col, val - '0');
                if (solve(board, index + 1)) {
                    return true;
                }
                clear(row, col, val - '0');
            }
        }

        board[row][col] = '.';
        return false;
    }

    public void fill(int row, int col, int val) {
        rowValid[row][val] = 1;
        columnValid[col][val] = 1;
        subBox[row / 3 * 3 + col / 3][val] = 1;
    }

    public void clear(int row, int col, int val) {
        rowValid[row][val] = 0;
        columnValid[col][val] = 0;
        subBox[row / 3 * 3 + col / 3][val] = 0;
    }

    public boolean isValid(int row, int col, int val) {
        return rowValid[row][val] == 0
                && columnValid[col][val] == 0
                && subBox[row / 3 * 3 + col / 3][val] == 0;
    }

    public void solveSudoku1(char[][] board) {
        solve(board, 1);
    }

    public static boolean solve1(char[][] board, int point) {
        if (point > 80) {
            return true;
        }
        int x = (point - 1) / 9;
        int y = (point - 1) % 9;
        if (board[x][y] != '.') {
            return solve1(board, point + 1);
        }
        for (int t = 1; t <= 9; t++) {
            if (check(board, x, y, t)) {
                board[x][y] = (char) (t + '0');
                if (solve1(board, point + 1)) {
                    return true;
                }
                board[x][y] = '.';
            }
        }
        return false;
    }

    public static boolean check(char[][] board, int x, int y, int value) {

        //行
        for (int t = 0; t < board.length; t++) {
            if (t != x && board[t][y] - '0' == value) {
                return false;
            }
        }
        //列
        for (int t = 0; t < board[0].length; t++) {
            if (t != y && board[x][t] - '0' == value) {
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
        //小方格
        for (int i = tx; i <= tx + 2; i++) {
            for (int j = ty; j <= ty + 2; j++) {
                if (i != x && j != y && board[i][j] - '0' == value) {
                    return false;
                }
            }
        }
        return true;
    }

}
