/**
* 验证二叉搜索树
*
* 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
*
* https://leetcode-cn.com/problems/validate-binary-search-tree
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    bool recur(TreeNode* root, int& max, int& min) {
        if (root == nullptr) {
            return true;
        }

        if (root->left == nullptr && root->right == nullptr) {
            min = root->val;
            max = root->val;
            return true;
        }

        if (root->left != nullptr) {
            int lmax;
            int lmin;
            if (!recur(root->left, lmax, lmin) || lmax >= root->val) {
                return false;
            }
            min = lmin;
        } else {
            min = root->val;
        }

        if (root->right != nullptr) {
            int rmax;
            int rmin;
            if (!recur(root->right, rmax, rmin) || rmin <= root->val) {
                return false;
            }
            max = rmax;
        } else {
            max = root->val;
        }

        return true;
    }

public:
    bool isValidBST(TreeNode* root) {
        int max; // 记录当前树的最大值
        int min; // 记录当前树的最小值
        return recur(root, max, min);
    }
};