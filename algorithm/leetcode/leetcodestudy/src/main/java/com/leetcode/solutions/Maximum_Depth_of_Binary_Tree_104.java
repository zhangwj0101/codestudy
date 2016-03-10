package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/10.
 */
public class Maximum_Depth_of_Binary_Tree_104 {

    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int dleft = maxDepth(root.left) + 1;
        int dright = maxDepth(root.right) + 1;
        return dleft > dright ? dleft : dright;
    }
}
