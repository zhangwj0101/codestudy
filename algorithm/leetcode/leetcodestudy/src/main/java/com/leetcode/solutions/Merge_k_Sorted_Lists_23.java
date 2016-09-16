/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import org.junit.Test;

import java.util.List;

/**
 * @author zhangwj
 */
public class Merge_k_Sorted_Lists_23 {

    @Test
    public void test() {
        ListNode[] res = new ListNode[3];
        res[0] = new ListNode(2);
        res[2] = new ListNode(-1);
        mergeKLists(res);
    }

    public ListNode mergeKLists(ListNode[] lists) {

        if (lists == null || lists.length < 1) {
            return null;
        }
        mergeKListsK(lists, 0, lists.length - 1);
        return lists[0];
    }

    private void mergeKListsK(ListNode[] lists, int left, int right) {

        if (left < right) {
            int mid = (left + right) / 2;
            mergeKListsK(lists, left, mid);
            mergeKListsK(lists, mid + 1, right);
            mergeTwoList(lists, left, mid + 1);
        }
    }

    private void mergeTwoList(ListNode[] lists, int left, int right) {
        if (left >= right) {
            return;
        }
        ListNode newHead = new ListNode(0);
        ListNode cur = newHead;
        ListNode l1 = lists[left];
        ListNode l2 = lists[right];
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                cur.next = l1;
                l1 = l1.next;
            } else {
                cur.next = l2;
                l2 = l2.next;
            }
            cur = cur.next;
        }
        cur.next = l1 == null ? l2 : l1;
        lists[left] = newHead.next;
    }
}
