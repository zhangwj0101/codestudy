package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/10.
 */
public class Symmetric_Tree_101 {

    public static void main(String[] args) {
        Symmetric_Tree_101 st = new Symmetric_Tree_101();
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(2);
        st.isSymmetric(root);
    }

    public boolean judge(TreeNode left, TreeNode right) {
        if (left == null && right == null) {
            return true;
        } else if (left == null && right != null || left != null && right == null) {
            return false;
        }
        return left.val == right.val && judge(left.left, right.right) && judge(left.right, right.left);

    }


    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }

        return judge(root.left, root.right);
    }


}


