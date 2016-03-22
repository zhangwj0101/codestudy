package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/16.
 */
public class Sum_Root_to_Leaf_Numbers_129 {


    public int get(TreeNode node, int pre) {
        if (node == null) {
            return 0;
        }
        int left = 0;
        int right = 0;
        pre = pre * 10 + node.val;
        if (node.left == null && node.right == null) {
            return pre;
        }
        if (node.left != null) {
            left = get(node.left, pre);
        }
        if (node.right != null) {
            right = get(node.right, pre);
        }
        return left + right;
    }

    public int sumNumbers(TreeNode node) {

        return get(node, 0);
    }
}
