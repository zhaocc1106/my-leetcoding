/**
 * 给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。
 * 你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
 * 返回获得利润的最大值。
 * 注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }

        int dp[n][2]; // 第一维代表天数，第二维代表当前日期是否持有股票
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp[i][0] = 0;
                dp[i][1] = -prices[i] - fee;
                continue;
            }
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i] - fee);
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