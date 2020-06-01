/**
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/
 */
package com.company;

public class swapPairs {
    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public static ListNode resolution(ListNode head) {
        ListNode prev = head;
        for (ListNode cur = head; cur != null && cur.next != null; cur = cur.next) {
            ListNode tmp = cur.next;
            cur.next = cur.next.next;
            tmp.next = cur;
            if (cur == head) {
                head = tmp;
                prev = cur;
            } else {
                prev.next = tmp;
                prev = prev.next.next;
            }

            if (cur.next == null || cur.next.next == null) {
                break;
            }
        }
        return head;
    }

    public static void main(String[] args) {
        ListNode node = new ListNode(1);
        node.next = new ListNode(2);
        node.next.next = new ListNode(3);
        node.next.next.next = new ListNode(4);
        ListNode head = resolution(node);
        for (ListNode cur = head; cur != null; cur = cur.next) {
            System.out.println(cur.val);
        }
    }
}
