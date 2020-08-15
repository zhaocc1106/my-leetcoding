/**
 * 二叉树中和为某一值的路径
 *
 * 输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。
 *
 * https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
 */

#include <iostream>
#include <vector>
#include <deque>

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
    vector <vector<int>> ans; // 保存所有的结果
    deque<TreeNode *> track; // 当前路径

    void backtrace(TreeNode *root, int sum) {
        if (root->left == nullptr && root->right == nullptr) { // 叶节点
            if (sum == root->val) { // 判断路径和是否满足需求
                if (track.size() > 0) {
                    vector<int> vec;
                    for (auto node : track) {
                        vec.push_back(node->val);
                    }
                    ans.push_back(vec);
                }
            }
            return;
        }

        if (root->left != nullptr) {
            track.push_back(root->left);
            backtrace(root->left, sum - root->val);
            track.pop_back();
        }
        if (root->right != nullptr) {
            track.push_back(root->right);
            backtrace(root->right, sum - root->val);
            track.pop_back();
        }
    }

    vector <vector<int>> pathSum(TreeNode *root, int sum) {
        if (root == nullptr) {
            return ans;
        }
        track.push_back(root);
        backtrace(root, sum);
        track.pop_back();
        return ans;
    }
};