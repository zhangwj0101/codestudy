/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

/**
 *
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

}
