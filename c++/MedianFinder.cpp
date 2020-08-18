/**
 * 数据流中的中位数
 *
 * 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个
 * 数值，那么中位数就是所有数值排序之后中间两个数的平均值。
 *
 * https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/
 */

#include <iostream>

using namespace std;

// 双向链表
struct Node {
    double val;
    Node *left;
    Node *right;

    Node(int x) : val(x), left(nullptr), right(nullptr) {};
};

class MedianFinder {
private:
    Node *head; // 双向链表头部
    Node *midL; // 中值节点的左边界
    Node *midR; // 中值节点的右边界，当中值节点的左边界==右边界，则代表当前总长度是奇数，如果左边界+1等于右边界，则代表当前长度为偶数
    Node *tail; // 双向链表的尾部

public:
    /** initialize your data structure here. */
    MedianFinder() {
        head = nullptr;
        midL = nullptr;
        midR = nullptr;
        tail = nullptr;
    }

    void addNum(int num) {
        if (head == nullptr) {
            // count << 1 << endl;
            head = new Node(num);
            tail = head;
            midL = head;
            midR = head;
            return;
        } else {
            if (midL->val >= num) { // 在midL左侧插入节点
                // count << 2 << endl;
                Node *cur = midL->left;
                for (; cur != nullptr && cur->val >= num; cur = cur->left);
                if (cur == nullptr) { // 头部的值仍然比当前值大，头部进行更换
                    // count << 3 << endl;
                    Node *node = new Node(num);
                    head->left = node;
                    node->right = head;
                    node->left = nullptr;
                    head = node;
                } else { // 当前cur元素比该值小，当前节点放在cur后面
                    // count << 4 << endl;
                    Node *node = new Node(num);
                    Node *tmp = cur->right;
                    node->left = cur;
                    node->right = tmp;
                    cur->right = node;
                    tmp->left = node;
                }

                if (midL == midR) { // 如果当前是奇数长度
                    // count << 5 << endl;
                    midL = midL->left; // 左边界左移一个
                } else { // 如果当前是偶数长度
                    // count << 6 << endl;
                    midR = midR->left; // 右边界左移一个
                }
            } else if (midR->val <= num) { // 在midR右侧插入节点
                // count << 7 << endl;
                Node *cur = midR->right;
                for (; cur != nullptr && cur->val <= num; cur = cur->right);
                if (cur == nullptr) { // 尾部的值仍然比当前值小，在尾部添加当前节点
                    // count << 8 << endl;
                    Node *node = new Node(num);
                    tail->right = node;
                    node->left = tail;
                    node->right = nullptr;
                    tail = node;
                } else { // 当前cur元素比该值大，当前节点放在cur前面
                    // count << 9 << endl;
                    Node *node = new Node(num);
                    Node *tmp = cur->left;
                    node->right = cur;
                    node->left = tmp;
                    cur->left = node;
                    tmp->right = node;
                }

                if (midL == midR) { // 如果当前是奇数长度
                    // count << 10 << endl;
                    midR = midR->right; // 右边界右移一个
                } else { // 如果当前是偶数长度
                    // count << 11 << endl;
                    midL = midL->right; // 左边界右移一个
                }
            } else { // 在midL和midR中间插入节点
                // count << 12 << endl;
                Node *node = new Node(num);
                node->right = midR;
                node->left = midL;
                midL->right = node;
                midR->left = node;

                midL = midR = node; // 由偶数长度变成奇数长度
            }
        }
    }

    double findMedian() {
        if (midL != nullptr && midR != nullptr) {
            // count << midL->val << ", " << midR->val << endl;
            return (midL->val + midR->val) / 2;
        }
        return -1;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 */
int main() {
    MedianFinder *obj = new MedianFinder();
    obj->addNum(2);
    obj->addNum(3);
    obj->addNum(1);
    obj->addNum(0);
    obj->addNum(4);
    obj->addNum(5);
    obj->addNum(3);
    obj->addNum(2);
    double res = obj->findMedian();
    cout << res << endl;
}