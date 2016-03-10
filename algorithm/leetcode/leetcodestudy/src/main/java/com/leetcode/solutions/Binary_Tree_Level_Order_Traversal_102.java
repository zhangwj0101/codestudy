package com.leetcode.solutions;

import java.util.*;

/**
 * Created by zhangwj on 16/3/10.
 */
public class Binary_Tree_Level_Order_Traversal_102 {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> results = new ArrayList<>();
        if (root == null) {
            return results;
        }
        Queue<TreeNode> queues = new ArrayDeque<>();
        queues.add(root);
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
            results.add(temp);
        }

        return results;
    }
}
