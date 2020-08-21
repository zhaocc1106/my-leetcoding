/**
 * II. 平衡二叉树
 *
 * 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
 *
 * https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/
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
    // 返回子树是否是平衡二叉树，并返回子树的深度
    bool subIsBalanced(TreeNode *root, int &depth) {
        if (root == nullptr) {
            depth = 0;
            return true;
        }

        int lDepth = 0;
        int rDepth = 0;

        if (subIsBalanced(root->left, lDepth) && subIsBalanced(root->right, rDepth)) {
            int sub = lDepth - rDepth;
            if (sub >= -1 && sub <= 1) {
                depth = max(lDepth, rDepth) + 1;
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    bool isBalanced(TreeNode *root) {
        int depth = 0;
        return subIsBalanced(root, depth);
    }
};