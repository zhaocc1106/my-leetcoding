/**
 * 树的子结构
 *
 * 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
 * B是A的子结构， 即 A中有出现和B相同的结构和节点值。
 *
 * https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
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

    // 判断B是否是A的子结构，以A节点开始判断
    bool recur(TreeNode *A, TreeNode *B) {
        if (B == nullptr) {
            return true;
        }

        if (A == nullptr || A->val != B->val) {
            return false;
        }

        return recur(A->left, B->left) && recur(A->right, B->right);
    }

    bool isSubStructure(TreeNode *A, TreeNode *B) {
        if (A == nullptr || B == nullptr) {
            return false;
        }

        return recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};