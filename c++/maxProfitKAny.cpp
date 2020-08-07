/**
 * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。注意: 
 * 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
 */

#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

class Solution {
public:
    static int maxProfitInf(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }

        int dp[n][2]; // 第一维代表天数，第二维代表当前日期是否持有股票
        memset(dp, 0, sizeof(dp));

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

    static int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if (k >= n / 2) { // 买卖股票的次数如果超过天数的一半，则相当于不受限制
            return maxProfitInf(prices);
        }

        // 第一维代表有多少天；第二维代表当前的交易次数；第三维代表当前是持有股票状态还是未持有股票状态
        // 这里的的第0天代表交易前一天，第0次交易代表没有交易
        int dp[n + 1][k + 1][2];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n + 1; i++) {
            dp[i][0][1] = INT_MIN; // 第i天，如果从来没有过交易，则不可能持有股票，不可能从这个状态转移
        }

        for (int i = 0; i < k + 1; i++) {
            dp[0][i][1] = INT_MIN; // 第0天，不可能持有股票
        }

        for (int i = 1; i < n + 1; i++) { // 遍历所有天
            for (int j = 1; j < k + 1; j++) { // 遍历所有的交易次数
                // 第i天第j次交易，如果未持有状态，则有可能是“第i-1天第j次交易未持有，今天继续不持有”；也有可能是“第i-1天，第
                // j次交易持有状态，并且今天卖出”，这个地方需要注意的是我们只在买入时将交易次数加一。
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i - 1]);

                // 第i天第j次交易，如果是持有状态，则有可能是“第i-1天第j次交易持有，今天继续持有”；也有可能是“第i-1天，第j-1次交易未
                // 持有，今天买入”，这个地方需要注意，因为买入时交易次数加一，所以这里是j-1。
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i - 1]);
            }
        }

        for (int i = 0; i < n + 1; i++) {
            cout << "The " << i << " day: ";
            for (int j = 0; j < k + 1; j++) {
                cout << "[" << dp[i][j][0] << ", " << dp[i][j][1] << "], ";
            }
            cout << endl;
        }

        return dp[n][k][0];
    }
};

int main() {
    vector<int> prices{3, 2, 6, 5, 0, 3};
    cout << Solution::maxProfit(2, prices);
}