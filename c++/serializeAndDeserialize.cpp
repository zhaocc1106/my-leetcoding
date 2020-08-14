/**
 * 二叉树的序列化与反序列化
 *
 * 序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另
 * 一个计算机环境，采取相反方式重构得到原数据。
 * 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个
 * 字符串并且将这个字符串反序列化为原始的树结构。
 *
 * https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/
 */

#include <iostream>
#include <deque>
#include <cstring>
#include <sstream>

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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        ostringstream out;
        deque<TreeNode *> nodes;
        nodes.push_back(root);
        while (!nodes.empty()) {
            TreeNode *node = nodes.front();
            nodes.pop_front();

            if (root != node) {
                out << " "; // 根节点前面没有逗号
            }
            if (node == nullptr) {
                out << "n";
            } else {
                out << to_string(node->val);
            }

            if (node != nullptr) {
                nodes.push_back(node->left);
                nodes.push_back(node->right);
            }
        }
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        istringstream input(data);

        TreeNode *root = nullptr;
        deque<TreeNode *> parentQue; // 顺序不为空的节点
        string lChild;
        while (input >> lChild) {
            cout << "lChild: " << lChild << endl;

            if (lChild != "") {
                if (root == nullptr) { // 根节点特殊处理
                    root = lChild != "n" ? new TreeNode(stoi(lChild)) : nullptr;
                    if (root == nullptr) {
                        break;
                    }
                    parentQue.push_back(root);
                } else {
                    // 获取当前父节点
                    TreeNode *parent = parentQue.front();
                    parentQue.pop_front();
                    cout << "parent: " << parent->val << endl;

                    // 处理左子树
                    parent->left = lChild != "n" ? new TreeNode(stoi(lChild)) : nullptr; // 左子树
                    if (parent->left != nullptr) {
                        parentQue.push_back(parent->left);
                    }

                    // 处理右子树
                    string rChild;
                    input >> rChild;
                    cout << "rChild: " << rChild << endl;
                    parent->right = rChild != "n" ? new TreeNode(stoi(rChild)) : nullptr; // 右子树
                    if (parent->right != nullptr) {
                        parentQue.push_back(parent->right);
                    }
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
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
    Codec codec;
    string serStr = codec.serialize(&node);
    cout << "serStr: " << serStr << endl;
    TreeNode *desNode = codec.deserialize(serStr);
    cout << "serStr2: " << codec.serialize(desNode) << endl;
}