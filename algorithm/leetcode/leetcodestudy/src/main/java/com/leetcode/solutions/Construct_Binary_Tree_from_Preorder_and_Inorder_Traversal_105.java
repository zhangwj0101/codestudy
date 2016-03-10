package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/10.
 */
public class Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_105 {

    public static void main(String[] args) {
        int[] preorder = {1, 2, 3};
        int[] inorder = {2, 3, 1};
        new Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_105().buildTree(preorder, inorder);
    }

    public TreeNode get(int[] preorder, int[] inorder, int i, int ileft, int iright) {
        if (ileft > iright) {
            return null;
        }
        int t = ileft;
        for (t = ileft; t <= iright && inorder[t] != preorder[i]; t++) ;
        TreeNode root = new TreeNode(preorder[i]);
        root.left = get(preorder, inorder, i + 1, ileft, t - 1);
        root.right = get(preorder, inorder, t - ileft + i + 1, t + 1, iright);
        return root;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {

        if (preorder.length != inorder.length || preorder.length < 1) {
            return null;
        }
        return get(preorder, inorder, 0, 0, inorder.length - 1);
    }
}
