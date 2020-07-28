/**
 * 零钱兑换
 * https://leetcode-cn.com/problems/coin-change/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1); // 动态规划数组，用来记录每个amount最少几个coins，初始值为amount+1代表异常值，方便求min
        dp[0] = 0; // 动态规划base
        for (int i = 1; i <= amount; i++) {
            for (auto coin : coins) {
                if (coin > i) { // 当前面值金额大于amount，则跳过
                    continue;
                }
                dp[i] = min(dp[i], dp[i - coin] + 1); // 选择较小coin个数放入到动规数组
            }
        }

        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};

int main() {
    vector<int> coins{1, 2, 5, 10};
    cout << Solution::coinChange(coins, 5);
}