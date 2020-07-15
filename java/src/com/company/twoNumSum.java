/**
 * https://leetcode-cn.com/problems/add-two-numbers/
 */

package com.company;

public class twoNumSum {

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode sumListNode = null;
        ListNode curNode = null;

        boolean ifCarry = false; // If carried by low level.
        /* Check if link node 1 has left node */
        for (; l1 != null; l1 = l1.next) { // Travel link node 1.
            int sum = l1.val + (ifCarry ? 1 : 0);
            if (l2 != null) {
                // If link node 2 has left node.
                sum = sum + l2.val;
                l2 = l2.next;
            }
            ifCarry = sum >= 10; // Update ifCarry.

            if (sumListNode == null) {
                sumListNode = new ListNode(sum % 10);
                curNode = sumListNode;
            } else {
                curNode.next = new ListNode(sum % 10);
                curNode = curNode.next;
            }
        }

        /* Check if link node 2 has left node */
        for (; l2 != null; l2 = l2.next) { // Travel left node of link node 2.
            int sum = l2.val + (ifCarry ? 1 : 0);
            ifCarry = sum >= 10; // Update ifCarry.

            if (sumListNode == null) {
                sumListNode = new ListNode(sum % 10);
                curNode = sumListNode;
            } else {
                curNode.next = new ListNode(sum % 10);
                curNode = curNode.next;
            }
        }

        /* Check if has left carrying. */
        if (ifCarry) {
            curNode.next = new ListNode(1);
        }

        return sumListNode;
    }

    public static void main(String[] args) {
        ListNode l1 = new ListNode(1);
        ListNode l2 = new ListNode(9);
        l2.next = new ListNode(9);
        l2.next.next = new ListNode(9);
        ListNode res = addTwoNumbers(l1, l2);
        for (; res != null; res = res.next) {
            System.out.print(res.val + "->");
        }
    }
}
