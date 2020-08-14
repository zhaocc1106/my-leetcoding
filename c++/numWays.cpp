/**
 * 青蛙跳台阶问题
 *
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
 * 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
 *
 * https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int numWays(int n) {
        if (n <= 1) {
            return n;
        }

        int pre2 = 1; // 上上个台阶有多少种跳法
        int pre1 = 1; // 上个台阶有多少种跳法
        int dp = 0; // 当前台阶有多少种跳法

        for (int i = 2; i <= n; i++) {
            dp = pre2 // 跳两级台阶
                 + pre1; // 跳一级
            dp = dp % 1000000007;
            pre2 = pre1;
            pre1 = dp;
        }

        return dp;
    }
};

int main () {
    cout << Solution().numWays(92);
}