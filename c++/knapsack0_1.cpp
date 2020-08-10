/**
 * 0-1背包问题
 *
 * 给你一个可装载重量为W的背包和N个物品，每个物品有重量和价值两个属性。其中第i个物品的重量为wt[i]，价值为val[i]，现在让你用这个背包装物品
 * ，最多能装的价值是多少？
 *
 * http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247485064&idx=1&sn=550705eb67f5e71487c8b218382919d6&chksm=9bd7
 * f880aca071962a5a17d0f85d979d6f0c5a5ce32c84b8fee88e36d451f9ccb3bb47b88f78&scene=21#wechat_redirect
 */

#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

class Solution {
public:
    int knapsack(int W, int N, vector<int> &wt, vector<int> &val) {
        int dp[N + 1][W + 1]; // 一维代表所有物品选择，二维代表当前背包的容量，元素值代表当前状态能获取的最大价值
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= W; j++) {
                if (j < wt[i - 1]) { // 如果当前背包容量已经不能够放下当前物品，则无法把当前物品放到背包里
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(
                            dp[i - 1][j], // 不选择该物品
                            dp[i - 1][j - wt[i - 1]] + val[i - 1] // 选择了该物品
                    );
                }
            }
        }

        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= W; j++) {
                cout << dp[i][j] << ",";
            }
            cout << endl;
        }

        return dp[N][W];
    }
};

int main() {
    int N = 3, W = 4;
    vector<int> wt = {2, 1, 3};
    vector<int> val = {4, 2, 3};
    cout << Solution().knapsack(W, N, wt, val);
}