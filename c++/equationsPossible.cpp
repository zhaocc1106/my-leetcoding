/**
 * 等式方程的可满足性
 *
 * 给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或
 *  "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。
 * 只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。
 *
 * https://leetcode-cn.com/problems/satisfiability-of-equality-equations/
 */

#include <iostream>
#include <vector>
#include "unionFind.h"

using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string> &equations) {
        UF uf(26); // 26个字符

        for (auto equa : equations) {
            if (equa[1] == '=') { // 相等的情况下，将字符联通
                uf.unionTree(equa[0] - 'a', equa[3] - 'a');
            }
        }

        for (auto equa :equations) {
            if (equa[1] == '!') { // 不相等的情况下，判断当前两个字符是否联通，如果联通了，则表达式不成立
                if (uf.connected(equa[0] - 'a', equa[3] - 'a')) {
                    return false;
                }
            }
        }

        return true;
    }
};