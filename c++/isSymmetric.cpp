/**
 * 对称的二叉树
 *
 * 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
 *
 * https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/
 */

#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    bool isMirror(TreeNode *rootL, TreeNode *rootR) {
        if (rootL == nullptr && rootR == nullptr) {
            return true;
        } else if (rootL == nullptr || rootR == nullptr) {
            return false;
        }

        // 判断根节点
        if (rootL->val != rootR->val) {
            return false;
        }
        // 判断rootL的左子树和rootR的右子树
        if (!isMirror(rootL->left, rootR->right)) {
            return false;
        }
        // 判断rootL的右子树和rootL的左子树
        return isMirror(rootL->right, rootR->left);
    }

    bool isSymmetric(TreeNode *root) {
        return isMirror(root, root);
    }
};