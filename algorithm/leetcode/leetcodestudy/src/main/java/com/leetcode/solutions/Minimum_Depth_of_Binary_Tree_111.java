package com.leetcode.solutions;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by zhangwj on 16/3/10.
 */
public class Minimum_Depth_of_Binary_Tree_111 {

    public int minDepth(TreeNode root) {

        if (root == null) {
            return 0;
        }

        return dfs(root);
    }

    /**
     * 递归的方式实现
     *
     * @param root
     * @return
     */
    public int dfs(TreeNode root) {

        if (root == null) {
            return 0;
        }

        if (root.left == null && root.right == null) {
            return 1;
        }
        return Math.min(dfs(root.left), dfs(root.right)) + 1;

    }

    /**
     * 队列的方式实现
     *
     * @param root
     * @return
     */
    public int minDepth1(TreeNode root) {

        if (root == null) {
            return 0;
        }
        int level = 0;
        Queue<TreeNode> queues = new LinkedList<>();
        queues.offer(root);
        while (!queues.isEmpty()) {
            level++;
            int size = queues.size();
            for (int i = 0; i < size; i++) {
                TreeNode t = queues.poll();
                if (t.left == null && t.right == null) {
                    return level;
                }
                if (t.left != null) {
                    queues.offer(t.left);
                }
                if (t.right != null) {
                    queues.offer(t.right);
                }
            }
        }
        return 0;
    }

}
