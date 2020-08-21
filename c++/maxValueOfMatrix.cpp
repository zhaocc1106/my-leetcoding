/**
 * 礼物的最大价值
 *
 * 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右
 * 或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
 *
 * https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
 */

#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dp[m + 1][n + 1]; // dp[i][j]表示运动到坐标(i-1, j-1)时所能获得的礼物最大值
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = max(dp[i - 1][j], // 由左边坐标右移而来
                               dp[i][j - 1])
                           + grid[i - 1][j - 1]; // 由上边坐标下移而来
            }
        }

        return dp[m][n];
    }
};
