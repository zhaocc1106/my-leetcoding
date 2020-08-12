/**
 *
 */

#include <iostream>
#include <vector>

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }

        if (l1->val > l2->val) { // 保证l1第一个值不比l2大
            ListNode *tmp = l1;
            l1 = l2;
            l2 = tmp;
        }

        ListNode *p1 = l1;
        ListNode *p2 = l2;
        while (p1 != nullptr && p2 != nullptr) {
            while (p1->next != nullptr && p1->next->val <= p2->val) {
                p1 = p1->next; // 寻找最后一个不比p2大的指针
            }
            // cout << "p1: " << p1->val << endl;
            if (p1->next == nullptr) {
                // p1为l1最后一个
                break;
            }
            ListNode *q2 = p2;
            while (q2->next != nullptr && q2->next->val <= p1->next->val) {
                q2 = q2->next; // 寻找l2中最后一个不比p1->next大的指针
            }
            // cout << "q2: " << q2->val << endl;
            ListNode *tmp = p1->next;
            ListNode *tmp2 = q2->next;
            q2->next = p1->next;
            p1->next = p2;
            p1 = tmp;
            p2 = tmp2;
        }
        // cout << p1->val << endl;
        if (p2 != nullptr) {
            p1->next = p2;
        }
        return l1;
    }

    ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2) {
        ListNode *ans = nullptr;
        ListNode *p = nullptr;
        while (l1 != nullptr && l2 != nullptr) {
            ListNode *min = nullptr;
            if (l1->val < l2->val) {
                min = l1;
                l1 = l1->next;
            } else {
                min = l2;
                l2 = l2->next;
            }
            if (ans == nullptr) {
                ans = min;
                p = min;
            } else {
                p->next = min;
                p = p->next;
            }
        }
        if (l1 != nullptr) {
            if (ans == nullptr) {
                ans = l1;
            } else {
                p->next = l1;
            }
        } else if (l2 != nullptr) {
            if (ans == nullptr) {
                ans = l2;
            } else {
                p->next = l2;
            }
        }
        return ans;
    }
};

int main() {
    ListNode a(1);
    ListNode b(2);
    ListNode c(4);
    ListNode d(1);
    ListNode e(3);
    ListNode f(4);
    a.next = &b;
    b.next = &c;
    d.next = &e;
    e.next = &f;
    ListNode *res = Solution().mergeTwoLists2(&a, &d);
    while (res != nullptr) {
        cout << res->val << ",";
        res = res->next;
    }
}