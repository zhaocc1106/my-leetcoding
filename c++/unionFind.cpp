/**
 * 联通分量算法源文件
 */

#include <iostream>
#include "unionFind.h"
#include <vector>

using namespace std;

UF::UF(int n) {
    count = n; // 默认所有的树都不联通
    for (int i = 0; i < n; i++) {
        parent.push_back(i); // 默认连通分量根节点是自己
        size.push_back(1); // 默认连通分量的节点个数均为1
    }
}

// 联通两个节点
void UF::unionTree(int p, int q) {
    int rootP = findRoot(p);
    int rootQ = findRoot(q);
    if (rootP == rootQ) {
        return; // 已经联通了
    }

    // 将较小的树连接到较大的树上，使树更平衡
    if (size[rootP] > size[rootQ]) {
        parent[rootQ] = rootP;
        size[rootP] += size[rootQ];
    } else {
        parent[rootP] = rootQ;
        size[rootQ] += size[rootP];
    }

    count--; // 非联通的树个数减一
}

// 判断两个节点是否联通
bool UF::connected(int p, int q) {
    return findRoot(p) == findRoot(q);
}

// 寻找连通分量的根节点
int UF::findRoot(int p) {
    while (parent[p] != p) {
        parent[p] = parent[parent[p]]; // 压缩连通分量路径
        p = parent[p];
    }
    return p;
}

// 返回非联通的树个数
int UF::unionCount() {
    return count;
}