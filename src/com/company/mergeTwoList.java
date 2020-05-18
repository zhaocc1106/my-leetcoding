/**
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/submissions/
 */

package com.company;

public class mergeTwoList {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {val = x;}
    }

    public static ListNode resolution(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        } else if (l2 == null) {
            return l1;
        }

        // l1头始终比l2头小
        if (l2.val < l1.val) {
            ListNode t = l1;
            l1 = l2;
            l2 = t;
        }

        ListNode cur1 = l1;
        ListNode cur2 = l2;
        for (; cur1.next != null; cur1 = cur1.next) {
            while(cur2 != null && cur2.val < cur1.next.val) {
                ListNode t = cur2.next;
                cur2.next = cur1.next;
                cur1.next = cur2;
                cur1 = cur2;
                cur2 = t;
            }
        }

        // l2有剩余
        if (cur2 != null) {
            cur1.next = cur2;
        }
        return l1;
    }
}
