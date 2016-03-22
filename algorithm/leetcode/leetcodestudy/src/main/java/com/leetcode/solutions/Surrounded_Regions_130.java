package com.leetcode.solutions;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by zhangwj on 16/3/16.
 */
public class Surrounded_Regions_130 {
    public void solve(char[][] board) {
        if (board == null || board.length == 0 || board[0].length == 0) {
            return;
        }

        int rows = board.length;
        int cols = board[0].length;

        // the first line and the last line.
        for (int j = 0; j < cols; j++) {
            bfs(board, 0, j);
            bfs(board, rows - 1, j);
        }

        // the left and right column
        for (int i = 0; i < rows; i++) {
            bfs(board, i, 0);
            bfs(board, i, cols - 1);
        }

        // capture all the nodes.
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'B') {
                    board[i][j] = 'O';
                }
            }
        }

        return;
    }


    public void bfs(char[][] board, int i, int j) {
        int rows = board.length;
        int cols = board[0].length;

        Queue<Integer> q = new LinkedList<Integer>();
        q.offer(i * cols + j);

        while (!q.isEmpty()) {
            int index = q.poll();

            int x = index / cols;
            int y = index % cols;

            if (board[x][y] != 'O') {
                continue;
            }
            board[x][y] = 'B';
            if (y < cols - 1) {
                q.offer(index + 1);
            }
            if (y > 0) {
                q.offer(index - 1);
            }

            if (x > 0) {
                q.offer(index - cols);
            }

            if (x < rows - 1) {
                q.offer(index + cols);
            }
        }
    }
}
