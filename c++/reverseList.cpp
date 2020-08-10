/**
 * 反转链表
 *
 * https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/
 */

/**
 * Definition for singly-linked list.
 */
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode *p = head;
        ListNode *q = p->next;
        while (true) {
            if (p == head) {
                p->next = NULL;
            }
            if (q == NULL) { // p已经是最后一个
                break;
            } else {
                ListNode *tmp = q->next;
                q->next = p;
                p = q;
                q = tmp;
            }
        }

        return p;
    }
};
