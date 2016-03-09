package com.leetcode.solutions;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by zhangwj on 16/3/9.
 */
public class Binary_Tree_Inorder_Traversal_94 {

    public void get(TreeNode root, List<Integer> results) {
        if (root == null) {
            return;
        }
        get(root.left, results);
        results.add(root.val);
        get(root.right, results);
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> results = new ArrayList<>();
        get(root, results);
        return results;
    }
}
