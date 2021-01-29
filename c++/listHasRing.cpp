/**
 * 有环链表相关题目
 *
 * https://www.cnblogs.com/yorkyang/p/10876604.html
 */

#include <iostream>

using namespace std;

struct Node {
    char val;
    Node *next;

    Node(char val) : val(val), next(nullptr) {};
};

class Solution {
public:

    // 是否有环
    bool hasRing(Node *node) {
        Node *slow = node, *fast = node; // 快慢指针

        while (slow != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next; // 快指针每次必慢指针多走一步

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }

    // 寻找节点的起始位置
    Node *findLoopStart(Node *node) {
        Node *slow = head, *fast = head; // 快慢指针

        bool have_circle = false;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next; // 快指针每次必慢指针多走一步

            if (slow == fast) {
                have_circle = true;
                break;
            }
        }

        if (!have_circle) {
            return nullptr;
        }

        Node *p = node; // 起点
        Node *q = slow; // 相遇节点

        while (p != q) { // 起始点到环入口点的位置==环入口点的位置-快慢指针相遇的点
            p = p->next;
            q = q->next;
        }

        return p;
    }

    // 环上节点的个数
    int ringCount(Node *root) {
        Node *slow = node, *fast = node; // 快慢指针

        while (slow != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next; // 快指针每次必慢指针多走一步

            if (slow == fast) {
                break;
            }
        }

        if (slow != fast) { // 没有环
            return 0;
        }

        int ans = 1;
        while (slow->next != slow) { // 慢指针跑一圈就是环节点的个数
            ans++;
            slow = slow->next;
        }

        return ans;
    }


};