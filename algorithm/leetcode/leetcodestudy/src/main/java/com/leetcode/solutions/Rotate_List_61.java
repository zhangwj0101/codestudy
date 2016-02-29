package com.leetcode.solutions;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * Created by zhangwj on 16/2/26.
 */
public class Rotate_List_61 {

    public static void main(String[] args) {
        ListNode s1 = new ListNode(1);
        ListNode s2 = new ListNode(2);
        s1.next = s2;
        ListNode re = rotateRight(s1, 1);
        while (re != null) {
            System.out.printf("%3d,", re.val);
            re = re.next;
        }
    }

    public static ListNode rotateRight(ListNode head, int k) {
        if (head == null || k < 1) {
            return head;
        }
        ListNode result = head;
        List<ListNode> lists = new ArrayList<>();
        ListNode p = head;
        while (p != null) {
            lists.add(p);
            p = p.next;
        }
        if (lists.size() == 1) {
            return head;
        }
        k = k > lists.size() ? k % lists.size() : k;
        if (k > 0 && k < lists.size()) {
            int pointer = lists.size() - k;
            result = lists.get(pointer);
            lists.get(pointer - 1).next = null;
            lists.get(lists.size() - 1).next = head;
        }
        return result;
    }


}
