package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/8.
 */
public class Remove_Duplicates_from_Sorted_List_II_82 {

    public ListNode deleteDuplicates(ListNode head) {

        if (head == null || head.next == null) {
            return head;
        }

        ListNode result = new ListNode(-1);
        ListNode p = head;
        ListNode pre = result;
        pre.next = head;
        ListNode cur = pre.next;
        p = p.next;

        boolean flag = false;
        while (p != null) {
            if (p.val == cur.val) {
                flag = true;
            } else {
                if (flag) {
                    cur = pre;
                    cur.next = p;
                    cur = cur.next;
                    flag = false;
                } else {
                    cur.next = p;
                    cur = cur.next;
                    pre = pre.next;
                }
            }
            p = p.next;
        }
        if (flag) {
            cur = pre;
            cur.next = null;

        }

        return result.next;
    }

}
