package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/8.
 */
public class Partition_List_86 {

    public static void main(String[] args) {
        Partition_List_86 p = new Partition_List_86();

        ListNode s1 = new ListNode(2);
        ListNode s2 = new ListNode(1);
        s1.next = s2;
        p.print(p.partition(s1, 2));
        System.out.print("df");
    }

    public void print(ListNode p) {

        while (p != null) {
            System.out.println(p.val + ",");
            p = p.next;
        }

    }

    public ListNode partition(ListNode head, int x) {

        ListNode min = new ListNode(0);
        ListNode max = new ListNode(1);

        ListNode minp = min;
        ListNode maxp = max;

        ListNode p = head;

        while (p != null) {
            if (p.val < x) {
                minp.next = p;
                minp = minp.next;
            } else {
                maxp.next = p;
                maxp = maxp.next;
            }
            p = p.next;
        }
        minp.next = max.next;
        maxp.next = null;
        return min.next;

    }
}
