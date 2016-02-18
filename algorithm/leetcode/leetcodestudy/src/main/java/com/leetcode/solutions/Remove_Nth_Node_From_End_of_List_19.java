/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

/**
 *
 * @author zhangwj
 */
public class Remove_Nth_Node_From_End_of_List_19 {

    public static void main(String[] args) {
        ListNode s1 = new ListNode(1);
        ListNode s2 = new ListNode(2);
        ListNode s3 = new ListNode(3);
        ListNode s4 = new ListNode(4);
        ListNode s5 = new ListNode(5);
        s1.next = s2;
        s2.next = s3;
        s3.next = s4;
        s4.next = s5;
        print(s1);
        print(removeNthFromEnd(s1, 4));
    }

    public static void print(ListNode p) {
        while (p != null) {
            System.out.print(" ," + p.val);
            p = p.next;
        }
        System.out.println("");
    }

    public static ListNode removeNthFromEnd(ListNode head, int n) {

        ListNode p = head;
        ListNode pre = head;
        int t = 0;
        int len = 0;
        while (p.next != null) {
            if (t < n) {
                t++;
            } else {
                pre = pre.next;
            }
            len++;
            p = p.next;
        }
        if (len == n - 1) {
            return pre.next;
        }
        pre.next = pre.next.next;

        return head;
    }
}
