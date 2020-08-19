/**
 * 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​
 * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 * 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

class Solution {
public:
    static int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }

        int dp[n + 1][2]; // 第一维代表天数，第二维代表当前日期是否持有股票
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 0;
        dp[0][1] = INT32_MIN; // 第0天无法购买股票，无法从当前状态转移
        for (int i = 1; i <= n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
            if (i == 1) {
                dp[i][1] = max(dp[i - 1][1], -prices[i - 1]);
            } else {
                dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i - 1]);
            }
        }

        for (int i = 0; i <= n; i++) {
            cout << dp[i][0] << ", " << dp[i][1] << endl;
        }

        return dp[n][0];
    }
};

int main() {
    vector<int> prices{1,2,3,0,2};
    cout << Solution::maxProfit(prices) << endl;
}