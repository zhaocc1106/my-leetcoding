/**
 * 回文链表
 *
 * 请判断一个链表是否为回文链表。
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/
 */

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    // 倒序链表解法，空间复杂度为o(n)
    bool isPalindrome(ListNode *head) {
        if (head == nullptr) {
            return true;
        }

        ListNode *reverseHead = nullptr; // 逆序链表头
        for (ListNode *p = head; p != nullptr; p = p->next) {
            ListNode *tmp = reverseHead;
            reverseHead = new ListNode(p->val);
            reverseHead->next = tmp;
        }

        ListNode *p = head, *q = reverseHead;
        for (; p != nullptr && q != nullptr && p->val == q->val; p = p->next, q = q->next);
        return p == nullptr && q == nullptr;
    }
};
