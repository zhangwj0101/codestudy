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

    public static void main(String[] args) {
        ListNode l1 = new ListNode(9);
        ListNode l12 = new ListNode(9);
        ListNode l13 = new ListNode(9);
        l1.next = l12;
        l12.next = l13;

        ListNode l2 = new ListNode(9);
        ListNode l22 = new ListNode(9);
        ListNode l23 = new ListNode(9);
        l2.next = l22;
        l22.next = l23;
        AddTwoNumbers_2 demo = new AddTwoNumbers_2();

//        ListNode addTwoNumbers = demo.addTwoNumbers(l1, l2);
        ListNode addTwoNumbers1 = demo.add1(l1, l2);
//
//        while (addTwoNumbers != null) {
//            System.out.print(addTwoNumbers.val + " --> ");
//            addTwoNumbers = addTwoNumbers.next;
//        }
//        System.out.println("");

        while (addTwoNumbers1 != null) {
            System.out.print(addTwoNumbers1.val + " --> ");
            addTwoNumbers1 = addTwoNumbers1.next;
        }

    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        long nanoTime = System.nanoTime();
        ListNode p = new ListNode(0);
        ListNode ret = p;
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
        System.out.println(System.nanoTime() - nanoTime);
        return ret;
    }

    public ListNode add(ListNode l1, ListNode l2) {
        long nanoTime = System.nanoTime();
        ListNode p = new ListNode(0);
        ListNode ret = p;
        int sum = 0;

        while (l1 != null) {
            p.val = l1.val;
            p = (p.next = new ListNode(0));
            l1 = l1.next;
        }
        p = ret;
        while (l2 != null) {
            sum += p.val + l2.val;
            p.val = sum % 10;
            sum /= sum;
            if (p.next == null) {
                p = (p.next = new ListNode(0));
            } else {
                p = p.next;
            }
            l2 = l2.next;
        }
        sum = 0;
        while (p != null && p.val + sum >= 10) {
            sum = p.val;
            p.val = sum % 10;
            sum /= 10;
            p = p.next;
        }
        System.out.println(System.nanoTime() - nanoTime);
        return ret;
    }

    public ListNode add1(ListNode l1, ListNode l2) {

        return null;
    }
}

class ListNode {

    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}
