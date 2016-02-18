/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import static com.leetcode.solutions.Remove_Nth_Node_From_End_of_List_19.print;

/**
 *
 * @author zhangwj
 */
public class Swap_Nodes_in_Pairs_24 {

    public static void main(String[] args) {
        ListNode s1 = new ListNode(1);
        ListNode s2 = new ListNode(2);
        s1.next = s2;
        ListNode s = swapPairs(s1);
        print(s);
    }

    public static ListNode swapPairs(ListNode head) {
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
}
