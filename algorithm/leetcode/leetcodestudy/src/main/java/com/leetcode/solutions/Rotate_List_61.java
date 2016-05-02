package com.leetcode.solutions;

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * Created by zhangwj on 16/2/26.
 */
public class Rotate_List_61 {

    @Test
    public void test() {
        ListNode s1 = new ListNode(1);
        ListNode s2 = new ListNode(2);
        s1.next = s2;
        ListNode re = rotateRight(s1, 1);
        while (re != null) {
            System.out.printf("%3d,", re.val);
            re = re.next;
        }
    }

    public ListNode rotateRight1(ListNode head, int n) {
        if (head == null) {
            return head;
        }

        int len = getLen(head);

        // 不需要重复地rotate.
        n = n % len;
        ListNode end = head;
        while (n > 0) {
            end = end.next;
            n--;
        }

        ListNode pre = head;
        while (end.next != null) {
            pre = pre.next;
            end = end.next;
        }
        // 这一句很重要，变成循环链表后，可以处理n = 0的情况。因为尾节点的下一个节点是头节点
        end.next = head;
        ListNode headNew = pre.next;
        pre.next = null;
        return headNew;
    }

    public int getLen(ListNode head) {
        int len = 0;
        while (head != null) {
            len++;
            head = head.next;
        }
        return len;
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
