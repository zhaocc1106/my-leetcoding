/**
 * https://leetcode-cn.com/problems/coin-change-2/
 */

#include <iostream>
#include <vector>

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
};

int main() {
    vector<int> coins{1, 2, 5};
    cout << Solution::change(5, coins) << endl;
}