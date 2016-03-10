package com.leetcode.solutions;

import java.util.*;

/**
 * Created by zhangwj on 16/3/10.
 */
public class Binary_Tree_Zigzag_Level_Order_Traversal_103 {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> results = new ArrayList<>();
        if (root == null) {
            return results;
        }
        Queue<TreeNode> queues = new ArrayDeque<>();
        queues.add(root);
        int time = 0;
        while (!queues.isEmpty()) {
            int len = queues.size();
            List<Integer> temp = new ArrayList<>();
            for (int i = 0; i < len; i++) {
                TreeNode remove = queues.remove();
                temp.add(remove.val);
                if (remove.left != null) {
                    queues.add(remove.left);
                }
                if (remove.right != null) {
                    queues.add(remove.right);
                }
            }
            if (time % 2 == 1) {
                Collections.reverse(temp);
            }
            results.add(temp);
            time++;
        }

        return results;
    }
}
