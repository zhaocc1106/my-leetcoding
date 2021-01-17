/**
* 不同的二叉搜索树
* 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
*
* https://leetcode-cn.com/problems/unique-binary-search-trees/
*/

#include <memory.h>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int dp[n + 1]; // 动态规划求解，dp[i]代表有i个元素时搜索树的个数
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) { // 挑出一个节点当根节点
                dp[i] += dp[j - 1] // 左孩子有多少种组合
                         * dp[i - j]; // 右孩子有多少种组合
            }
        }

        return dp[n];
    }
};
