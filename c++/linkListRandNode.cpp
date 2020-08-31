/**
 * 链表随机节点
 *
 * 给定一个单链表，随机选择链表的一个节点，并返回相应的节点值。保证每个节点被选的概率一样。
 *
 * 进阶:
 * 如果链表十分大且长度未知，如何解决这个问题？你能否使用常数级空间复杂度实现？
 *
 * https://leetcode-cn.com/problems/linked-list-random-node/
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
private:
    ListNode *head;

public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head) : head(head) {
    }

    /** Returns a random node's value. */
    int getRandom() {
        int i = 1;
        int ans;
        for (ListNode *cur = head; cur != nullptr; cur = cur->next, i++) {
            // 生成一个[0, count)的整数，当为0，代表概率为1/i。
            // 第i个元素被选择的概率为1/i，第i+1次不被替换的概率为1-1/(i+1)，第i+2次不被替换的概率为1-1/(i+2)。依次类推，最后全
            // 部相乘即为1/n
            if (rand() % i == 0) {
                ans = cur->val;
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main() {
    cout << rand() % 10 << endl;
}