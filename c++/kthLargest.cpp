/**
 * 二叉搜索树的第k大节点
 *
 * 给定一棵二叉搜索树，请找出其中第k大的节点。
 *
 * https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
 */

#include <iostream>
#include <vector>

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
    // 中序遍历节点，树展开成有序数组
    void inorderTrav(TreeNode *root, vector<int> &arr) {
        if (root == nullptr) {
            return;
        }
        inorderTrav(root->left, arr);
        arr.push_back(root->val);
        inorderTrav(root->right, arr);
    }

    int kthLargest(TreeNode *root, int k) {
        vector<int> arr;
        inorderTrav(root, arr);
        return arr[arr.size() - k];
    }
};