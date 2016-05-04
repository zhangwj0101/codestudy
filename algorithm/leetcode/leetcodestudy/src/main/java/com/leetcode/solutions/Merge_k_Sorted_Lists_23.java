/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

/**
 * @author zhangwj
 */
public class Merge_k_Sorted_Lists_23 {

    public static void main(String[] args) {

    }

    public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode p1 = l1;
        ListNode p2 = l2;
        ListNode result = new ListNode(0);
        ListNode temp = result;
        while (p1 != null && p2 != null) {
            if (p1.val < p2.val) {
                result = (result.next = p1);
                p1 = p1.next;
            } else {
                result = (result.next = p2);
                p2 = p2.next;
            }
        }
        result.next = (p1 == null) ? p2 : p1;
        return temp.next;
    }

    public static void merge(ListNode[] lists, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            merge(lists, left, mid);
            merge(lists, mid + 1, right);
            ListNode result = lists[left];
            for (int i = left + 1; i <= right; i++) {
                result = mergeTwoLists(result, lists[i]);
                lists[i] = null;
            }
            lists[left] = result;
        }
    }

    public static ListNode mergeKLists(ListNode[] lists) {
        if (lists.length < 1) {
            return null;
        }
        merge(lists, 0, lists.length - 1);
        return lists[0];
    }
}
