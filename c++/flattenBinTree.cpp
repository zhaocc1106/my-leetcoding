/**
* 二叉树展开为链表
*
* 给定一个二叉树，原地将它展开为一个单链表。
*
* https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
*/

#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    /* 递归并且返回当前树对应单链表的尾部 */
    TreeNode* recur(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* tail;
        TreeNode* lchild = root->left;
        TreeNode* rchild = root->right;

        tail = root;
        if (lchild != nullptr) {
            TreeNode* ltail = recur(lchild);
            tail->right = lchild;
            tail = ltail;
            tail->left = nullptr;
        }

        if (rchild != nullptr) {
            TreeNode* rtail = recur(rchild);
            tail->right = rchild;
            tail = rtail;
            tail->left = nullptr;
        }

        root->left = nullptr;
        // cout << "root: " << root->val << ", tail: " << tail->val << endl;
        return tail;
    }

public:
    void flatten(TreeNode* root) {
        TreeNode* tail = recur(root);
        tail->left = nullptr;
        tail->right = nullptr;
    }
};

int main() {
    TreeNode root(1);
    TreeNode node1(2);
    TreeNode node2(3);
    TreeNode node3(4);
    TreeNode node4(5);
    TreeNode node5(6);

    root.left = &node1;
    root.right = &node4;

    node1.left = &node2;
    node1.right = &node3;

    node4.left = nullptr;
    node4.right = &node5;

    Solution().flatten(&root);

    cout << "flatten finish" << endl;

    for (TreeNode* node = &root; node != nullptr; node = node->right) {
        cout << node->val << node->left << ", ";
    }
}