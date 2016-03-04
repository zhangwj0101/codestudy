package com.leetcode.solutions;

import java.util.List;

/**
 * Created by zhangwj on 16/3/4.
 */
public class Remove_Duplicates_from_Sorted_List_83 {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode p = head;
        ListNode result = head;
        ListNode pre = head;
        p = p.next;
        while (p != null) {
            if (p.val != pre.val) {
                pre.next = p;
                pre = pre.next;
            }
            p = p.next;
        }
        pre.next = null;
        return result;
    }
}
