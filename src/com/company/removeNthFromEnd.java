package com.company;

import java.util.ArrayList;
import java.util.List;

public class removeNthFromEnd {

    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public static ListNode resolution(ListNode head, int n) {
        List<ListNode> listArr = new ArrayList<ListNode>();
        for (ListNode cur = head; cur != null; cur = cur.next) {
            listArr.add(cur);
        }
        if (listArr.size() - n - 1 >= 0) {
            ListNode nthPreNode = listArr.get(listArr.size() - n - 1); // The previous node of last nth node.
            nthPreNode.next = nthPreNode.next.next;
            return head;
        } else {
            return head.next;
        }
    }

    public static void main(String[] args) {

    }
}
