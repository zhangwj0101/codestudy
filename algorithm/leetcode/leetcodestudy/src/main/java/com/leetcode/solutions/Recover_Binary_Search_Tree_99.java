package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/4.
 */
public class Recover_Binary_Search_Tree_99 {
    TreeNode pre = null;
    TreeNode first = null;
    TreeNode second = null;

    public void recoverTree(TreeNode root) {
        inOrder(root);

        // swap the value of first and second node.
        int tmp = first.val;
        first.val = second.val;
        second.val = tmp;
    }

    public void inOrder(TreeNode root) {
        if (root == null) {
            return;
        }

        // inorder traverse.
        inOrder(root.left);

        // 判断 pre 是否已经设置
        if (pre != null && pre.val > root.val) {
            if (first == null) {
                // 首次找到反序.
                first = pre;
                second = root;
            } else {
                // 第二次找到反序，更新Second.
                second = root;
            }
        }

        pre = root;

        // inorder traverse.
        inOrder(root.right);
    }
}
