/**
 * 二叉搜索树与双向链表
 *
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
 *
 * https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
 */

#include <iostream>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    // 函数返回两个节点，分别是子树的最小节点和最大节点
    vector<Node *> subTreeToDoublyList(Node *root) {
        if (root == nullptr) {
            return {nullptr, nullptr};
        }

        vector<Node *> ans(2, nullptr);

        vector<Node *> leftAns = subTreeToDoublyList(root->left);
        vector<Node *> rightAns = subTreeToDoublyList(root->right);

        if (leftAns[1] != nullptr) {
            leftAns[1]->right = root;
            root->left = leftAns[1];
        }
        if (leftAns[0] != nullptr) {
            ans[0] = leftAns[0];
        } else {
            ans[0] = root;
        }

        if (rightAns[0] != nullptr) {
            rightAns[0]->left = root;
            root->right = rightAns[0];
        }
        if (rightAns[1] != nullptr) {
            ans[1] = rightAns[1];
        } else {
            ans[1] = root;
        }

        return ans;
    }

    Node *treeToDoublyList(Node *root) {
        vector<Node *> ans = subTreeToDoublyList(root);
        if (ans[0] != nullptr) {
            ans[0]->left = ans[1];
        }
        if (ans[1] != nullptr) {
            ans[1]->right = ans[0];
        }
        return ans[0];
    }
};