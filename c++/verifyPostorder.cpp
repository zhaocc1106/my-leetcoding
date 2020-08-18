/**
 * 二叉搜索树的后序遍历序列
 *
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互
 * 不相同。
 *
 * https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int root = INT_MAX;
        stack<int> s;
        for (int i = postorder.size() - 1; i >= 0; i--) {
            if (postorder[i] > root) {
                return false;
            }
            while (!s.empty() && s.top() > postorder[i]) {
                root = s.top();
                s.pop();
            }
            s.push(postorder[i]);
        }
        return true;
    }
};