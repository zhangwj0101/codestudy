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
public class Swap_Nodes_in_Pairs_24 {

    @Test
    public void main() {
        ListNode s1 = new ListNode(1);
        ListNode s2 = new ListNode(2);
        s1.next = s2;
        ListNode s = swapPairs1(s1);
    }

    public ListNode swapPairs(ListNode head) {
        ListNode s1 = new ListNode(0);
        ListNode s2 = new ListNode(0);
        ListNode result = new ListNode(0);
        ListNode ss1 = s1, ss2 = s2, rres = result;
        int t = 0;
        while (head != null) {
            if (t % 2 == 1) {
                s1.next = head;
                s1 = head;
            } else {
                s2.next = head;
                s2 = head;
            }
            t++;
            head = head.next;
            s1.next = null;
            s2.next = null;
        }
        ss1 = ss1.next;
        ss2 = ss2.next;
        while (ss1 != null && ss2 != null) {
            result.next = ss1;
            result = result.next;
            ss1 = ss1.next;
            result.next = ss2;
            result = result.next;
            ss2 = ss2.next;
            result.next = null;
        }
        result.next = (ss1 == null) ? ss2 : ss1;
        return rres.next;
    }

    public ListNode swapPairs1(ListNode head) {
        return reverse2Group(head, 2);
    }

    public ListNode reverse2Group(ListNode head, int k) {

        if (k < 2) {
            return head;
        }
        ListNode cur = head;
        ListNode pre = null, start = null;
        ListNode next = null;
        int count = 1;
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

        ListNode next = null, pre = null, st = start;
        while (start != right) {
            next = start.next;
            start.next = pre;
            pre = start;
            start = next;
        }
        if (left != null) {
            left.next = pre;
        }
        st.next = right;


    }

}
