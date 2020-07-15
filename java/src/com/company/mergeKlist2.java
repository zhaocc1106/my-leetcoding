/**
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/submissions/
 * 分治法，假设有k个链表，则时间复杂度为o(kn * log(k))，空间复杂度为log(k)，log(k)为分治法的递归深度。
 */

package com.company;

public class mergeKlist2 {

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public static ListNode merge2list(ListNode l1, ListNode l2) {
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
            while (cur2 != null && cur2.val < cur1.next.val) {
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

    public static ListNode merge(ListNode[] lists, int l, int r) {
        if (l == r) {
            return lists[l];
        }
        if (l > r) {
            return null;
        }
        int mid = (l + r) / 2;
        return merge2list(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    public static ListNode mergeKlist(ListNode[] lists) {
        return merge(lists, 0, lists.length - 1);
    }

}
