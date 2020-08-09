/**
 * 链表中倒数第k个节点
 * https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
 */

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getKthFromEnd(ListNode *head, int k) {
        if (head == NULL) {
            return NULL;
        }

        ListNode *p = head; // 慢指针
        ListNode *q = head; // 快指针
        int i = 0; // p和q的间隔

        // 保持q比p大k-1
        for (; i < k - 1 && q != NULL; i++, q = q->next);
        cout << i << endl;
        if (i != k - 1) { // 链表长度比k-1小，直接返回
            return NULL;
        }

        for (; q != NULL && q->next != NULL; q = q->next, p = p->next);

        return p;
    }
};