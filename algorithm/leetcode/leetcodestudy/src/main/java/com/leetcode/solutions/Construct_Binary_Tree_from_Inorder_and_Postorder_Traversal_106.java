package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/10.
 */
public class Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal_106 {

    public TreeNode get(int[] inorder, int[] postorder, int i, int ileft, int iright) {
        if (ileft > iright) {
            return null;
        }
        int t = ileft;
        for (t = ileft; t <= iright && inorder[t] != postorder[i]; t++) ;
        TreeNode root = new TreeNode(postorder[i]);
        root.left = get(inorder, postorder, i - 1 + t - iright, ileft, t - 1);
        root.right = get(inorder, postorder, i - 1, t + 1, iright);
        return root;

    }

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (postorder.length != inorder.length || postorder.length < 1) {
            return null;
        }
        return get(inorder, postorder, postorder.length - 1, 0, postorder.length - 1);
    }
}
