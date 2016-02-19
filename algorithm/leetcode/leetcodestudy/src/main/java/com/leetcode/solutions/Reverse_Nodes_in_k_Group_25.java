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
public class Reverse_Nodes_in_k_Group_25 {

    public static void main(String[] args) {

        ListNode s1 = new ListNode(1);
        ListNode s2 = new ListNode(2);
        s1.next = s2;
        ListNode reverseKGroup = reverseKGroup(s1, 2);
        print(reverseKGroup);
    }

    public static ListNode reverseKGroup(ListNode head, int k) {

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
}
