/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;


import org.junit.Test;

/**
 * @author zhangwj
 */
public class Reverse_Nodes_in_k_Group_25 {

    @Test
    public void main() {

        ListNode s1 = new ListNode(1);
        ListNode s2 = new ListNode(2);
//        ListNode s3 = new ListNode(3);
        s1.next = s2;
//        s2.next = s3;
        ListNode reverseKGroup = reverseKGroup2(s1, 2);
    }

    public ListNode reverseKGroup(ListNode head, int k) {

        if (k == 1) {
            return head;
        }
        ListNode p = head;
        ListNode result = new ListNode(0);
        ListNode[] tempLists = new ListNode[k];
        ListNode rres = result;
        while (p != null) {
            int i = 0;
            ListNode left = new ListNode(0);
            ListNode rleft = left;
            for (i = 0; i < k && p != null; i++) {
                left.next = p;
                tempLists[i] = p;
                p = p.next;
                left = left.next;
                left.next = null;
            }
            if (i == k) {
                for (i = k - 1; i >= 0; i--) {
                    result.next = tempLists[i];
                    result = result.next;
                    result.next = null;
                }
            } else {
                result.next = rleft.next;
                result = left;
            }
        }
        return rres.next;
    }


    public ListNode reverseKGroup2(ListNode head, int k) {

        if (k < 2) {
            return head;
        }
        int count = 1;
        ListNode cur = head;
        ListNode start = null, pre = null, next = null;
        while (cur != null) {
            next = cur.next;
            if (count == k) {
                start = pre == null ? head : pre.next;
                head = pre == null ? cur : head;
                reverse(pre, start, cur, next);
                pre = start;
                count = 0;
            }
            count++;
            cur = next;
        }
        return head;
    }

    public void reverse(ListNode left, ListNode start, ListNode end, ListNode right) {

        ListNode next = null;
        ListNode pre = null;
        ListNode st = start;
        while (start != right) {
            next = start.next;
            start.next = pre;
            pre = start;
            start = next;
        }
        st.next = right;
        if (left != null) {
            left.next = pre;
        }
    }
}
