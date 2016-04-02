package com.leetcode.solutions;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by zhangwj on 16/3/10.
 */
public class Maximum_Depth_of_Binary_Tree_104 {


    /**
     * 递归的方式
     *
     * @param root
     * @return
     */
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
    }

    /**
     * 队列的方式
     *
     * @param root
     * @return
     */
    public int maxDepth1(TreeNode root) {
        if (root == null) {
            return 0;
        }
        Queue<TreeNode> queues = new LinkedList<>();
        queues.add(root);
        int level = 0;
        while (!queues.isEmpty()) {
            int len = queues.size();
            level++;
            for (int i = 0; i < len; i++) {
                TreeNode t = queues.poll();
                if (t.left != null) {
                    queues.offer(t.left);
                }
                if (t.right != null) {
                    queues.offer(t.right);
                }
            }
        }
        return level;
    }
}
