/**
 * 戳气球
 *
 * 有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
 * 现在要求你戳破所有的气球。如果你戳破气球 i ，就可以获得 nums[left] * nums[i] * nums[right] 个硬币。 这里的 left 和 right 
 * 代表和 i 相邻的两个气球的序号。注意当你戳破了气球 i 后，气球 left 和气球 right 就变成了相邻的气球。
 * 求所能获得硬币的最大数量。
 *
 * https://leetcode-cn.com/problems/burst-balloons/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> coins; // 存储所有气球种硬币的数量，-1和n存放1
    vector<vector<int>> dp; // 形状为(n + 2) * (n + 2)，存放所有解决(i, j)区域最优值
public:
    // 求边界(i, j)的最优解，开区间
    int solve(int i, int j) {
        if (i >= j - 1) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        for (int k = i + 1; k < j; k++) {
            int val = coins[k] * coins[i] * coins[j] + solve(i, k) + solve(k, j);
            dp[i][j] = max(val, dp[i][j]);
        }
        return dp[i][j];
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        coins.resize(n + 2);
        for (int i = 1; i <= n; i++) {
            coins[i] = nums[i - 1];
        }
        coins[0] = coins[n + 1] = 1;

        dp.resize(n + 2, vector<int>(n + 2, -1));
        return solve(0, n + 1);
    }
};