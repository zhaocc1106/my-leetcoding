/**
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次
 * 买卖一支股票）。注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }

        int dp[n][2]; // 第一维代表天数，第二维代表当前日期是否持有股票
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        for (int i = 0; i < n; i++) {
            cout << dp[i][0] << ", " << dp[i][1] << endl;
        }

        return dp[n - 1][0];
    }
};

int main() {
    vector<int> prices{7, 1, 5, 3, 6, 4};
    cout << Solution::maxProfit(prices) << endl;
}