package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/2.
 */
public class Word_Search_79 {

    public boolean get(char[][] board, int i, int j, int k, String word) {
        if (k >= word.length()) {
            return true;
        }
        if (i < 0 || i >= board.length
                || j < 0 || j >= board[0].length
                || board[i][j] == '#'
                || board[i][j] != word.charAt(k)) {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '#';
        boolean flag = false;
        flag = get(board, i, j + 1, k + 1, word)
                || get(board, i + 1, j, k + 1, word)
                || get(board, i, j - 1, k + 1, word)
                || get(board, i - 1, j, k + 1, word);
        board[i][j] = temp;
        return flag;
    }

    public boolean exist(char[][] board, String word) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == word.charAt(0)) {
                    if (get(board, i, j, 0, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}
