/**
 * n个骰子的点数
 *
 * 把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
 * 你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。
 *
 * https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/
 */

#include <iostream>
#include <vector>
#include <memory.h>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<double> twoSum(int n) {
        int dp[n + 1][n * 6 + 1]; // dp[i][j]代表掷色子i次，和为j组合次数
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= 6; i++) { // 掷一次色子，则每个和都最多出现1次
            dp[1][i] = 1;
        }

        for (int i = 2; i <= n; i++) { // 从掷第二次色子开始
            for (int j = i; j <= n * 6; j++) { // 和肯定大于等于掷色子次数
                for (int k = 1; k <= 6; k++) {
                    if (j - k <= 0) {
                        break;
                    }
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }

        int count = pow(6, n);
        vector<double> ans;
        for (int i = n; i <= 6 *n; i++) {
            ans.push_back(dp[n][i] * 1.0 / count);
        }
        return ans;
    }
};

int main() {

}