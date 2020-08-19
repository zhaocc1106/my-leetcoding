/**
 * 两个链表的第一个公共节点
 *
 * 输入两个链表，找出它们的第一个公共节点。
 *
 * https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
 */

#include <iostream>
#include <unordered_set>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set < ListNode * > nodes;
        for (; headA != nullptr; headA = headA->next) {
            nodes.insert(headA);
        }
        for (; headB != nullptr; headB = headB->next) {
            if (nodes.count(headB) > 0) {
                return headB;
            }
        }
        return nullptr;
    }

    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        ListNode *node1 = headA;
        ListNode *node2 = headB;

        while (node1 != node2) {
            node1 = node1 == nullptr ? headB : node1->next;
            node2 = node2 == nullptr ? headA : node2->next;
        }

        return node1;
    }
};