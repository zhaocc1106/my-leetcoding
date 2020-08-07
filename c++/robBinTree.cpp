/**
 * 打家劫舍 III
 *
 * 在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有
 * 且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚
 * 上被打劫，房屋将自动报警。计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
 *
 * https://leetcode-cn.com/problems/house-robber-iii
 */

#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int subRob(TreeNode *root, unordered_map<TreeNode *, int> &dp) {
        if (root == nullptr) {
            return 0;
        }

        if (dp.count(root) > 0) {
            return dp[root];
        }

        // 如果打劫当前节点，则打劫子节点的子节点
        int robNow = root->val
                     + (root->left == nullptr ? 0 : subRob(root->left->left, dp) + subRob(root->left->right, dp))
                     + (root->right == nullptr ? 0 : subRob(root->right->left, dp) + subRob(root->right->right, dp));
        // 如果不打劫当前节点，则打劫两个子节点
        int robNext = subRob(root->left, dp) + subRob(root->right, dp);

        dp[root] = max(robNow, robNext);

        return dp[root];
    }

    int rob(TreeNode *root) {
        unordered_map<TreeNode *, int> dp;
        return subRob(root, dp);
    }
};

int main() {
}