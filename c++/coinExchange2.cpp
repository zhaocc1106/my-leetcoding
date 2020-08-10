/**
 * 零钱兑换 II
 * https://leetcode-cn.com/problems/coin-change-2/
 */

#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

class Solution {
public:
    static int change(int amount, vector<int> &coins) {
        vector<int> dp(amount + 1, 0); // 动态规划数组，存放每个amount组合个数
        dp[0] = 1;
        for (auto coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        for (auto item : dp) {
            cout << item << ", ";
        }
        cout << endl;
        return dp[amount];
    }

    static int change1(int amount, vector<int> &coins) {
        int dp[coins.size() + 1][amount + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= coins.size(); i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j] // 不选择
                        + (j - coins[i - 1] >= 0 ? dp[i][j - coins[i - 1]] : 0); // 选择
            }
        }
        return dp[coins.size()][amount];
    }
};

int main() {
    vector<int> coins{1, 2, 5};
    cout << Solution::change1(5, coins) << endl;
}