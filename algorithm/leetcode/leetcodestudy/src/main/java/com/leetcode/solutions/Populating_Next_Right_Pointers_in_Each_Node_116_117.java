package com.leetcode.solutions;

import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by zwj on 2016/3/12.
 */
public class Populating_Next_Right_Pointers_in_Each_Node_116_117 {
    public void connect(TreeLinkNode root) {
        if (root == null) {
            return;
        }

        Queue<TreeLinkNode> q = new LinkedList<TreeLinkNode>();
        q.offer(root);

        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeLinkNode cur = q.poll();
                cur.next = (i == size - 1) ? null : q.peek();
                if (cur.left != null) {
                    q.offer(cur.left);
                    q.offer(cur.right);
                }
            }
        }
    }

    /**
     * 递归的方式实现
     *
     * @param root
     */
    public void rec(TreeLinkNode root) {
        if (root == null) {
            return;
        }

        if (root.left != null) {
            root.left.next = root.right;
        }

        if (root.right != null) {
            root.right.next = root.next == null ? null : root.next.left;
        }

        rec(root.left);
        rec(root.right);
    }

    public void connect2(TreeLinkNode root) {
        if (root == null) {
            return;
        }

        TreeLinkNode leftEnd = root;
        while (leftEnd != null && leftEnd.left != null) {
            TreeLinkNode cur = leftEnd;
            while (cur != null) {
                cur.left.next = cur.right;
                cur.right.next = cur.next == null ? null : cur.next.left;

                cur = cur.next;
            }

            leftEnd = leftEnd.left;
        }
    }

    public void connect117(TreeLinkNode root) {
        if (root == null) {
            return;
        }

        TreeLinkNode leftEnd = root;

        while (leftEnd != null) {
            TreeLinkNode cur = leftEnd;
            TreeLinkNode dummy = new TreeLinkNode(0);
            TreeLinkNode pre = dummy;
            while (cur != null) {
                if (cur.left != null) {
                    pre.next = cur.left;
                    pre = cur.left;
                }

                if (cur.right != null) {
                    pre.next = cur.right;
                    pre = cur.right;
                }

                cur = cur.next;
            }
            leftEnd = dummy.next;
        }
    }
}


class TreeLinkNode {
    int val;
    TreeLinkNode left, right, next;

    TreeLinkNode(int x) {
        val = x;
    }
}
