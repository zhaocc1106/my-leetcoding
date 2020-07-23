/**
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
 */

#include <iostream>
#include <queue>

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
    static int minDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        queue<TreeNode*> nodes;
        nodes.push(root);

        int steps = 1;
        while (!nodes.empty()) {
            int len = nodes.size();
            for (int i = 0; i < len; i++) {
                TreeNode *node = nodes.front();
                nodes.pop();
                if (node->left == NULL && node->right == NULL) {
                    return steps;
                }
                if (node->left != NULL) {
                    nodes.push(node->left);
                }
                if (node->right != NULL) {
                    nodes.push(node->right);
                }
            }
            steps++;
        }
    }
};

int main() {
}