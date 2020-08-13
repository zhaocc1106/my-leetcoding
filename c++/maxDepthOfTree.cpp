/**
 * 二叉树的深度
 *
 * https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/
 */

#include <iostream>
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
    int depth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        deque<TreeNode *> nodes; // 存放所有节点
        nodes.push_back(root);
        nodes.push_back(nullptr); // nullptr 代表这一层的结束

        int ans = 1;
        while (!nodes.empty()) {
            TreeNode *node = nodes.front();
            nodes.pop_front();

            if (node != nullptr) { // 如果当前层未结束
                if (node->left != nullptr) {
                    nodes.push_back(node->left);
                }
                if (node->right != nullptr) {
                    nodes.push_back(node->right);
                }
            } else { //当前层结束了
                if (nodes.size() > 0) { // 如果还有层次没遍历
                    ans++;
                    nodes.push_back(nullptr); // 插入层结束符nullptr
                }
            }
        }
        return ans;
    }

    int depth2(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + max(depth2(root->left), depth2(root->right));
    }
};

int main() {
    TreeNode node(3);
    TreeNode node1(9);
    TreeNode node2(20);
    TreeNode node3(15);
    TreeNode node4(7);
    node.left = &node1;
    node.right = &node2;
    node2.left = &node3;
    node2.right = &node4;
    cout << Solution().depth2(&node);
}