package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/10.
 */
public class Minimum_Depth_of_Binary_Tree_111 {

    public int minDepth(TreeNode root) {

        if (root == null) {
            return 0;
        }
        int ldep = Integer.MAX_VALUE;
        int rdep = Integer.MAX_VALUE;
        if (root.left == null && root.right == null) {
            return 1;
        }
        if (root.left != null) {
            ldep = minDepth(root.left) + 1;
        }
        if (root.right != null) {
            rdep = minDepth(root.right) + 1;
        }
        return Math.min(ldep, rdep);
    }
}
