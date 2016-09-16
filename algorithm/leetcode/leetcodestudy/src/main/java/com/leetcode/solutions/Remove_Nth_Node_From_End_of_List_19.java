/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import java.util.ArrayList;
import java.util.List;

/**
 * @author zhangwj
 */
public class Remove_Nth_Node_From_End_of_List_19 {


    public static ListNode removeNthFromEnd(ListNode head, int n) {

        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode slow = dummy;
        ListNode fast = dummy;

        while (n > 0) {
            fast = fast.next;
            n--;
        }
        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        slow.next = slow.next.next;

        return dummy.next;
    }

    public static ListNode removeNthFromEnd1(ListNode head, int n) {

        ListNode fast = head;
        ListNode slow = head;
        if (n < 0) {
            return head;
        }
        while (n >= 0 && fast != null) {
            fast = fast.next;
            n--;
        }
        if (n >= 0) {
            return fast == null ? head.next : head;
        }
        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }

        slow.next = slow.next.next;
        return head;
    }
}
