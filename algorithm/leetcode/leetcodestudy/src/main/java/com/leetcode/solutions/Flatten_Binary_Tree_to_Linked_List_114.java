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

    /**
     * 递归的方式解决
     *
     * @param root
     * @return
     */
    // return : the tail of the list.
    public TreeNode dfs(TreeNode root) {
        if (root == null) {
            return null;
        }

        TreeNode left = root.left;
        TreeNode right = root.right;

        // Init the root.
        root.left = null;
        root.right = null;

        TreeNode tail = root;

        // connect the left tree.
        if (left != null) {
            tail.right = left;
            tail = dfs(left);
        }

        // connect the right tree.
        if (right != null) {
            tail.right = right;
            tail = dfs(right);
        }

        return tail;
    }
}
