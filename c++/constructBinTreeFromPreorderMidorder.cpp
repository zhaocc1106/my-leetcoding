/**
 * 从前序与中序遍历序列构造二叉树
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
 */
#include <iostream>
#include <vector>
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
    static unordered_map<int, int> index;

    static TreeNode *myBuildTree(const vector<int> &preorder, const vector<int> &inorder, int leftPreorder,
                                 int rightPreorder, int leftInorder, int rightInorder) {
        if (leftPreorder > rightPreorder) {
            return NULL;
        }

        int preorderRootVal = preorder[leftPreorder]; // 根节点的值
        int inorderRootInd = index[preorderRootVal]; // 根节点在中序的位置

        TreeNode *inorderRoot = new TreeNode(preorderRootVal); // 构建根节点

        int sizeOfLeftTreePreorder = inorderRootInd - leftInorder; // 左子树前序数组的长度

        // 递归构建左子树
        inorderRoot->left = myBuildTree(preorder, inorder, leftPreorder + 1, leftPreorder + sizeOfLeftTreePreorder,
                leftInorder, inorderRootInd - 1);
        // 递归构建右子树
        inorderRoot->right = myBuildTree(preorder, inorder, leftPreorder + sizeOfLeftTreePreorder + 1, rightPreorder,
                inorderRootInd + 1, rightInorder);
        return inorderRoot;
    }

    static TreeNode *buildTree(const vector<int> &preorder, const vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i; // 构建map映射inorder的值和标签，方便寻找根节点的位置
        }
        myBuildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};