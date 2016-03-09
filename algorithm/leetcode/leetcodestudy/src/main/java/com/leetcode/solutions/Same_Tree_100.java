package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/4.
 */
public class Same_Tree_100 {

    public boolean isSameTree(TreeNode p, TreeNode q) {
        return judge(p, q);
    }

    public boolean judge(TreeNode p, TreeNode q) {
        if (p == null && q == null) {
            return true;
        }
        if ((p == null && q != null)
                || (p != null && q == null)
                ) {
            return false;
        }
        if (p.val != q.val) {
            return false;
        }
        return judge(p.left, q.left) && judge(p.right, q.right);
    }

}

class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }

    
}
