/**
 * 二叉树的锯齿形层次遍历
 *
 * 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
 * https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }

        deque<TreeNode *> nodes; // 存放所有节点
        auto *level = new deque<TreeNode *>(); // 存放每一层的节点
        vector<vector<int>> ans; // 存放结果
        ans.push_back({root->val});

        nodes.push_back(root);
        nodes.push_back(nullptr); // nullptr 代表这一层的结束

        bool left = true; // 是否向左遍历
        while (!nodes.empty()) {
            TreeNode *node = nodes.front();
            nodes.pop_front();

            if (node != nullptr) { // 如果当前层未结束
                // cout << node->val << endl;
                if (node->left != nullptr) {
                    nodes.push_back(node->left);
                    if (left) {
                        level->push_front(node->left); // 每次将节点放入最开始，这样顺序读取的时候就相当于从右到左了
                    } else {
                        level->push_back(node->left); // 每次将节点放入最末尾，这样顺序读取的时候就相当于从左到右了
                    }
                }
                if (node->right != nullptr) {
                    nodes.push_back(node->right);
                    if (left) {
                        level->push_front(node->right); // 每次将节点放入最开始，这样顺序读取的时候就相当于从右到左了
                    } else {
                        level->push_back(node->right); // 每次将节点放入最末尾，这样顺序读取的时候就相当于从左到右了
                    }
                }
            } else { //当前层结束了
                // cout << "new level size: " << level->size() << endl;
                if (level->size() > 0) {
                    vector<int> levelAns;
                    for (auto iter = level->begin(); iter != level->end(); iter++) { // 顺序将当前层放入到结果中
                        levelAns.push_back((*iter)->val);
                    }
                    ans.push_back(levelAns);
                }

                // 创建新的层次遍历队列
                delete level;
                level = new deque<TreeNode *>();

                if (nodes.size() > 0) { // 如果还有层次没遍历
                    nodes.push_back(nullptr); // 插入层结束符nullptr
                    left = !left; // 转变方向
                }
            }
        }
        return ans;
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
    vector<vector<int>> ans = Solution().zigzagLevelOrder(&node);
    for (auto level : ans) {
        for (auto item : level) {
            cout << item << ", ";
        }
        cout << endl;
    }
}