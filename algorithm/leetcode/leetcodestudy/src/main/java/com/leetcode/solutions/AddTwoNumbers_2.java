/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

/**
 * @author zhangwj
 */
public class AddTwoNumbers_2 {

    public ListNode addTwoNumbers1(ListNode l1, ListNode l2) {
        ListNode p = new ListNode(0);
        ListNode res = p;
        int sum = 0;
        while (true) {
            if (l1 != null) {
                sum += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                sum += l2.val;
                l2 = l2.next;
            }
            p.val = sum % 10;
            sum /= 10;
            if (l1 != null || l2 != null || sum != 0) {
                p = (p.next = new ListNode(0));
            } else {
                break;
            }
        }
        return res;
    }
}

class ListNode {

    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}
