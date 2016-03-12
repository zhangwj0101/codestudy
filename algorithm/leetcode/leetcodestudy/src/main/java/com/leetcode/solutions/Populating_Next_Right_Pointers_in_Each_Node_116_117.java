package com.leetcode.solutions;

import java.util.ArrayDeque;
import java.util.Queue;

/**
 * Created by zwj on 2016/3/12.
 */
public class Populating_Next_Right_Pointers_in_Each_Node_116_117 {
    public void connect(TreeLinkNode root) {

        if (root == null) {
            return;
        }
        Queue<TreeLinkNode> queues = new ArrayDeque<>();
        queues.add(root);
        while (!queues.isEmpty()) {
            int len = queues.size();
            TreeLinkNode t = queues.poll();
            if (t.left != null) {
                queues.add(t.left);
            }
            if (t.right != null) {
                queues.add(t.right);
            }
            for (int i = 1; i < len; i++) {
                TreeLinkNode temp = queues.poll();
                if (temp.left != null) {
                    queues.add(temp.left);
                }
                if (temp.right != null) {
                    queues.add(temp.right);
                }
                t.next = temp;
                t = t.next;
            }
            t.next = null;
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
