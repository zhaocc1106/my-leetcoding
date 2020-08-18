/**
 * 二叉树中的最大路径和
 *
 * 给定一个非空二叉树，返回其最大路径和。
 * 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 *
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/submissions/
 */

#include <iostream>
#include <vector>
#include <climits>

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
private:
    int maxLen = INT_MIN;

public:

    // 求当前root为根节点的树的最大增益，
    int maxGain(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int leftGain = max(maxGain(root->left), 0); // 递归求左子树的最大增益
        int rightGain = max(maxGain(root->right), 0); // 求右子树

        maxLen = max(maxLen, leftGain + rightGain + root->val); // 如果当前树的路径是最大值，则更新

        return max(root->val + leftGain, root->val + rightGain);
    }

    int maxPathSum(TreeNode *root) {
        maxGain(root);
        return maxLen;
    }
};