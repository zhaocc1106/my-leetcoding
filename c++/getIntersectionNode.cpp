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

    ListNode *getIntersectionNode3(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        ListNode* quick = headA; // 每次走两步
        ListNode* slow = headA; // 每次走一步
        ListNode* tailA = nullptr; // 记录A的尾部

        // 连接headA尾部与headB头部
        while (quick != nullptr) {
            if (quick->next != nullptr) {
                if (quick->next->next == nullptr) {
                    tailA = quick->next;
                    quick->next->next = headB; // 连接headA尾部和headB头部
                    quick = headB;
                    slow = slow->next;
                    break;
                } else {
                    quick = quick->next->next;
                    slow = slow->next;
                }
            } else {
                tailA = quick;
                quick->next = headB; // 连接headA尾部和headB头部
                quick = headB->next;
                slow = slow->next;
                break;
            }
        }
        // cout << "link finish." << endl;

        // 查看连接好的链表是否有环
        bool have_ring = false;
        while (quick != nullptr && quick->next != nullptr) {
            slow = slow->next;
            quick = quick->next->next;
            if (quick == slow) {
                have_ring = true;
                break;
            }
        }

        if (!have_ring) { // 没有环，即没有相交点
            tailA->next = nullptr; // 断开A尾部与B头部
            return nullptr;
        }

        // 快慢指针在环中相遇的节点到环起始位置的距离等于链表起始位置到环起始位置
        ListNode* ans = headA;
        while (slow != ans) {
            slow = slow->next;
            ans = ans->next;
        }

        tailA->next = nullptr; // 断开A尾部与B头部
        return ans;
    }
};