/**
 * 买卖股票的最佳时机
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算
 * 你所能获取的最大利润。注意：你不能在买入股票前卖出股票。
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
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

        int dp[n][2]; // 第一维代表所有天，第二维代表持有或者未持有股票对应的最大收益

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp[0][0] = 0; // 第一天未持有股票的最大收益为0
                dp[0][1] = -prices[0]; // 第一天持有股票最大收益为当天股价的负值
                continue;
            }

            // 第i天，如果是未持有状态，则最大收益要么是昨天未持有，今天继续不持有；要么是昨天持有，今天卖掉获得的收益
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);

            // 第i天，如果是持有状态，则最大收益要么是昨天持有，今天继续持有；要么是昨天没持有，今天买入获得的收益。注意这里收益是负值，
            // 求上述较大者目的是为了找到最便宜的股价买入
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
        }
        return dp[n - 1][0];
    }

    static int maxProfit2(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }

        int dp_pre_0 = 0; // 表示前一天未持有股价的时候最大收益，初始为0
        int dp_pre_1 = -prices[0]; // 表示前一天持有股票的最大收益，初始为第一天股价的负值

        for (int i = 1; i < n; i++) {
            // 第i天，如果是未持有状态，则最大收益要么是昨天未持有，今天继续不持有；要么是昨天持有，今天卖掉获得的收益
            dp_pre_0 = max(dp_pre_0, dp_pre_1 + prices[i]);

            // 第i天，如果是持有状态，则最大收益要么是昨天持有，今天继续持有；要么是昨天没持有，今天买入获得的收益。注意这里收益是负值，
            // 求上述较大者目的是为了找到最便宜的股价买入
            dp_pre_1 = max(dp_pre_1, -prices[i]);
        }
        return dp_pre_0;
    }
};

int main() {
    vector<int> prices{7, 2, 7, 1, 7, 4};
    cout << Solution::maxProfit(prices);
}