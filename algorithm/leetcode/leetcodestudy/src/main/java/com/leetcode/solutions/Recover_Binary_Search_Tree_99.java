package com.leetcode.solutions;

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by zhangwj on 16/3/4.
 */
public class Recover_Binary_Search_Tree_99 {
    TreeNode pre = null;
    TreeNode first = null;
    TreeNode second = null;

    public void recoverTree(TreeNode root) {
        inOrder(root);

        int tmp = first.val;
        first.val = second.val;
        second.val = tmp;
    }

    public void inOrder(TreeNode root) {
        if (root == null) {
            return;
        }

        inOrder(root.left);
        if (pre != null && pre.val > root.val) {
            if (first == null) {
                first = pre;
                second = root;
            } else {
                second = root;
            }
        }
        pre = root;
        inOrder(root.right);
    }

    @Test
    public void tes() {
        List s = new ArrayList<String>();
        List<Object> s1 = s;
    }
}
