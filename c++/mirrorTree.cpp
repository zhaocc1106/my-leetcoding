/**
 * 二叉树的镜像
 *
 * 请完成一个函数，输入一个二叉树，该函数输出它的镜像。
 *
 * https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/
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
    void mirror(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        mirror(node->left);
        mirror(node->right);
        TreeNode *tmp = node->right;
        node->right = node->left;
        node->left = tmp;
    }

    TreeNode *mirrorTree(TreeNode *root) {
        mirror(root);
        return root;
    }
};