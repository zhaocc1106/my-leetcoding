/**
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
 */

package com.company;


public class reverseKGroup {
    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    // 逆序一个group
    public static ListNode reverseGroup(ListNode groupHead, ListNode groupTail) {
        ListNode prev = groupHead;
        ListNode cur = groupHead.next;
        while (true) {
            ListNode tmp = cur.next;
            cur.next = prev;
            prev = cur;
            if (cur == groupTail) {
                groupHead.next = tmp;
                break;
            }
            cur = tmp;
        }
        return groupTail;
    }

    public static ListNode resolution(ListNode head, int k) {
        ListNode prevGroupTail = head; // 记录上一个group的尾
        ListNode groupHead = head; // 记录一个group的头
        ListNode groupTail = head.next;  // 记录一个group的尾
        if (groupHead == null || groupTail == null) {
            return head;
        }

        int groupSize = 1; // 记录一个group的size
        while (groupTail != null) {
            groupSize++;
            if (groupSize == k) {
                // System.out.println(groupSize);
                // System.out.println("reverseGroup head: " + groupHead.val + " tail: " + groupTail.val);
                ListNode reversedGroupHead = reverseGroup(groupHead, groupTail); // 逆序一个group
                if (prevGroupTail == head) {
                    head = reversedGroupHead;
                } else {
                    prevGroupTail.next = reversedGroupHead; // 连接上一个group的尾部和新逆序的group的头部
                }
                prevGroupTail = groupHead; // 更新上一个group的尾部节点为新逆序的group的尾部

                groupHead = prevGroupTail.next; // 更新新group的头部
                if (groupHead == null) { // 如果新的group的头部为空，则结束迭代
                    break;
                }
                groupSize = 1; // 更新新的group的size
                groupTail = groupHead.next; // 更新新的group的尾部
                continue;
            }
            groupTail = groupTail.next;
        }

        // 连接剩余的节点
        if (groupSize < k) {
            prevGroupTail.next = groupHead;
        }
        return head;
    }

    public static void main(String args[]) {
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        ListNode node4 = new ListNode(4);
        ListNode node5 = new ListNode(5);
        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node5;

        for (ListNode cur = node1; cur != null; cur = cur.next) {
            System.out.print(cur.val);
        }
        System.out.println("");
        ListNode reverseNode = resolution(node1, 4);
        for (ListNode cur = reverseNode; cur != null; cur = cur.next) {
            System.out.print(cur.val);
        }
    }
}
