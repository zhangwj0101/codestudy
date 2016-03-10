package com.leetcode.solutions;

import java.util.ArrayDeque;
import java.util.Queue;

/**
 * Created by zhangwj on 16/3/10.
 */
public class Symmetric_Tree_101 {

    public static void main(String[] args) {
        Symmetric_Tree_101 st = new Symmetric_Tree_101();
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(2);
        st.isSymmetric(root);
    }


    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode[] temp = new TreeNode[queue.size()];
            queue.toArray(temp);
            queue.clear();
            for (int i = 0; i < temp.length / 2; i++) {
                if (temp[i] == null && temp[i] == temp[temp.length - 1 - i]) {
                    continue;
                }
                if (temp[i].val != temp[temp.length - 1 - i].val) {
                    return false;
                }
            }
            for (int i = 0; i < temp.length; i++) {
                if (temp[i] == null) {
                    continue;
                }
                queue.add(temp[i].left);
                queue.add(temp[i].right);
            }
        }

        return true;
    }

}
