/**
 * 排序链表
 *
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 *
 * https://leetcode-cn.com/problems/sort-list/solution/
 */

#include <iostream>

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
private:
    ListNode *mergeSort(ListNode *head) {
        if (head->next == nullptr) {
            return head;
        }

        ListNode *mid = head; // 中间节点
        ListNode *quick = head; // 快指针，用于找到中间节点
        for (; quick->next != nullptr &&
               quick->next->next != nullptr; mid = mid->next, quick = quick->next->next); // 找到中间节点
        ListNode *midNext = mid->next;
        mid->next = nullptr; // 切分成左右两部分
        ListNode *l = mergeSort(head); // 归并排序左半部分
        ListNode *r = mergeSort(midNext); // 归并排序右半部分

        // 合并局部结果
        ListNode *merge = nullptr;
        ListNode *cur = nullptr;
        while (l != nullptr && r != nullptr) {
            ListNode *little = l->val >= r->val ? r : l; // 选取较小节点
            if (merge == nullptr) {
                merge = little;
                cur = merge;
            } else {
                cur->next = little;
                cur = little;
            }
            if (little == l) {
                l = l->next;
            } else {
                r = r->next;
            }
        }

        // 添加剩余节点
        if (l == nullptr) {
            cur->next = r;
        } else {
            cur->next = l;
        }

        return merge;
    }

public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }

        return mergeSort(head);
    }
};

int main() {
    ListNode *node1 = new ListNode(2);
    node1->next = new ListNode(1);
    node1->next->next = new ListNode(1);
    node1->next->next->next = new ListNode(0);
    node1->next->next->next->next = new ListNode(4);
    ListNode *head = Solution().sortList(node1);
    while (head != nullptr) {
        cout << head->val;
        head = head->next;
    }
}

