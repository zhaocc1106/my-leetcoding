/**
 * 最小路径和
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 *
 * 说明：每次只能向下或者向右移动一步。
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/
 */

#include <vector>
#include <memory.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }

        int n = grid[0].size();
        if (n == 0) {
            return 0;
        }

        int dp[m][n];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) { // 左上角是第一个位置，无法从别的地方移动过来
                    dp[i][j] = grid[i][j];
                    continue;
                }
                if (i == 0) { // 第一行只能从左边移动过来
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                    continue;
                }
                if (j == 0) { // 第一列只能从上边移动过来
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                    continue;
                }
                dp[i][j] = min(dp[i][j - 1], // 从左边移动过来
                               dp[i - 1][j]) // 从上边移动过来
                           + grid[i][j];
            }
        }

        return dp[m - 1][n - 1];
    }
};