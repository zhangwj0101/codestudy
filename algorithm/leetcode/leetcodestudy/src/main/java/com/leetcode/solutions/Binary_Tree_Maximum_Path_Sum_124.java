package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/15.
 */
public class Binary_Tree_Maximum_Path_Sum_124 {

    public int maxPathSum(TreeNode root) {
        return dfs(root).max;
    }

    public TNode dfs(TreeNode root) {
        TNode ret = new TNode(Integer.MIN_VALUE, Integer.MIN_VALUE);
        if (root == null) {
            return ret;
        }
        TNode left = dfs(root.left);
        TNode right = dfs(root.right);

        int cross = Math.max(left.maxS, 0) + Math.max(0, right.maxS) + root.val;

        int maxS = Math.max(Math.max(left.maxS, right.maxS), 0) + root.val;

        int max = Math.max(left.max, right.max);
        ret.maxS = maxS;
        ret.max = Math.max(max, cross);
        return ret;
    }

    class TNode {
        int max;
        int maxS;

        public TNode(int max, int maxS) {
            this.max = max;
            this.maxS = maxS;
        }
    }
}






