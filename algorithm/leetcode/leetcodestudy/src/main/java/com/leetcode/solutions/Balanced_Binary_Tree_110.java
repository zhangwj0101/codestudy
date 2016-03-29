package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/10.
 */
public class Balanced_Binary_Tree_110 {
    public int get(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int ldep = get(root.left);
        if (ldep == -1) {
            return -1;
        }
        int rdep = get(root.right);
        if (rdep == -1) {
            return -1;
        }
        if (Math.abs(ldep - rdep) >= 2) {
            return -1;
        }
        return Math.max(rdep + 1, ldep + 1);

    }

    public boolean isBalanced(TreeNode root) {

        int result = get(root);
        return result != -1;
    }


}
