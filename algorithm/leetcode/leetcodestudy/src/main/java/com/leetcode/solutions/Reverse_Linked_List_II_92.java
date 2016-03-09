package com.leetcode.solutions;

import java.util.Stack;

/**
 * Created by zhangwj on 16/3/8.
 */
public class Reverse_Linked_List_II_92 {

    public static void main(String[] args) {
        Reverse_Linked_List_II_92 s = new Reverse_Linked_List_II_92();
        ListNode s1 = new ListNode(3);
        ListNode s2 = new ListNode(5);
        s1.next = s2;
        ListNode result = s.reverseBetween(s1, 1, 2);
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
        ListNode st = result;
        Stack<ListNode> stacks = new Stack<>();
        int len = 0;
        while (p != null) {
            len++;
            if (len < m || len > n) {
                result.next = p;
                result = result.next;
            } else if (len < n) {
                stacks.push(p);
            } else {
                ListNode tem = p;
                p = p.next;
                tem.next = null;
                stacks.push(tem);
                while (!stacks.isEmpty()) {
                    result.next = stacks.pop();
                    result = result.next;
                }
                continue;
            }

            p = p.next;
        }
        result.next = null;
        return st.next;
    }
}
