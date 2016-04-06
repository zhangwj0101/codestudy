package com.leetcode.solutions;

import org.junit.Test;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

/**
 * Created by zhangwj on 16/3/8.
 */
public class Reverse_Linked_List_II_92 {

    @Test
    public void tesr() {
        Reverse_Linked_List_II_92 s = new Reverse_Linked_List_II_92();
        ListNode s1 = new ListNode(3);
        ListNode s2 = new ListNode(5);
        s1.next = s2;
        ListNode result = s.reverseBetween(s1, 2, 2);
        s.print(result);
    }

    public void print(ListNode p) {

        while (p != null) {
            System.out.println(p.val + ",");
            p = p.next;
        }

    }

    public ListNode reverseBetween(ListNode head, int m, int n) {

        ListNode p = head;
        ListNode result = new ListNode(0);
        result.next = p;
        ListNode pre = result;
        int len = 0;
        Stack<ListNode> stacks = new Stack<>();

        while (p != null) {
            len++;
            if (len < m) {
                pre = p;
            } else if (len >= m && len <= n) {
                stacks.push(p);
            } else if (len > n) {
                break;
            }
            p = p.next;
        }
        while (!stacks.isEmpty()) {
            ListNode node = stacks.pop();
            pre.next = node;
            pre = pre.next;
        }
        pre.next = p;
        return result.next;
    }
}
