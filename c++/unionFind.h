/**
 * 动态连接性算法头文件
 */

#ifndef MY_LEETCODING_UNIONFIND_H
#define MY_LEETCODING_UNIONFIND_H

#include <vector>

class UF {
private:
    int count; // 连通分量个数，即不连通的树的个数
    std::vector<int> parent; // 记录森林
    std::vector<int> size; // 记录每棵树的大小

public:
    UF(int n); // 构造函数
    void unionTree(int p, int q); // 联通p和q节点
    bool connected(int p, int q); // 判断p和q节点是否联通
    int findRoot(int p); // 寻找p节点的根节点
    int unionCount(); // 返回非联通树的个数
};

#endif //MY_LEETCODING_UNIONFIND_H
