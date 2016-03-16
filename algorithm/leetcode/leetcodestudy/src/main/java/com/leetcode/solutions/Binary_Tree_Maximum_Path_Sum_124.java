package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/15.
 */
public class Binary_Tree_Maximum_Path_Sum_124 {
    public class ReturnType {
        int maxSingle;
        int max;

        ReturnType(int maxSingle, int max) {
            this.max = max;
            this.maxSingle = maxSingle;
        }
    }

    public int maxPathSum(TreeNode root) {
        return dfs(root).max;
    }

    public ReturnType dfs(TreeNode root) {
        ReturnType ret = new ReturnType(Integer.MIN_VALUE, Integer.MIN_VALUE);
        if (root == null) {
            return ret;
        }

        ReturnType left = dfs(root.left);
        ReturnType right = dfs(root.right);

        int cross = root.val;

        // if any of the path of left and right is below 0, don't add it.
        cross += Math.max(0, left.maxSingle);
        cross += Math.max(0, right.maxSingle);

        // 注意，这里不可以把Math.max(left.maxSingle, right.maxSingle) 与root.val加起来，
        // 会有可能越界！
        int maxSingle = Math.max(left.maxSingle, right.maxSingle);

        // may left.maxSingle and right.maxSingle are below 0
        maxSingle = Math.max(maxSingle, 0);
        maxSingle += root.val;

        ret.maxSingle = maxSingle;
        ret.max = Math.max(right.max, left.max);
        ret.max = Math.max(ret.max, cross);

        return ret;
    }

}
