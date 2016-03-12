package com.leetcode.solutions;

import java.util.Stack;

/**
 * Created by zwj on 2016/3/12.
 */
public class Flatten_Binary_Tree_to_Linked_List_114 {

    public void flatten(TreeNode root) {
        if (root == null) {
            return;
        }
        TreeNode p = root;
        Stack<TreeNode> stacks = new Stack<>();
        if (root.right != null) {
            stacks.push(root.right);
        }
        if (root.left != null) {
            stacks.push(root.left);
        }
        while (!stacks.empty()) {
            TreeNode node = stacks.pop();
            p.right = node;
            p.left = null;
            p = p.right;
            if (node.right != null) {
                stacks.push(node.right);
            }
            if (node.left != null) {
                stacks.push(node.left);
            }
        }
    }
}
