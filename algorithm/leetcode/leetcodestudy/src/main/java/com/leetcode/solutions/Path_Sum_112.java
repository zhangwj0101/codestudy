package com.leetcode.solutions;

import org.junit.Test;

/**
 * Created by zwj on 2016/3/12.
 */
public class Path_Sum_112 {

    public boolean get(TreeNode node, int subsum, int sum) {
        subsum += node.val;
        if (node.left != null && node.right != null) {
            return get(node.left, subsum, sum) || get(node.right, subsum, sum);
        } else if (node.left != null && node.right == null) {
            return get(node.left, subsum, sum);
        } else if (node.left == null && node.right != null) {
            return get(node.right, subsum, sum);
        } else if (node.left == null && node.right == null) {
            return subsum == sum;
        }
        return false;
    }

    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) {
            return false;
        }
        return get(root, 0, sum);
    }

    @Test
    public void test() {
        TreeNode s1 = new TreeNode(1);
        TreeNode s2 = new TreeNode(-2);
        TreeNode s3 = new TreeNode(1);
        TreeNode s4 = new TreeNode(3);
        TreeNode s5 = new TreeNode(-1);
        s1.left = s2;
        s2.left = s3;
        s2.right = s4;
        s3.left = s5;
        System.out.print(hasPathSum(s1, 2));

    }
}
