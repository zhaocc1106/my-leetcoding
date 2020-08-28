/**
 * 跳跃游戏 II
 *
 * 给定一个非负整数数组，你最初位于数组的第一个位置。
 *
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 *
 * 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
 *
 * https://leetcode-cn.com/problems/jump-game-ii/
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

class Solution {
public:
    // o(n * n)，会超时
    int jump(vector<int> &nums) {
        int m = nums.size();
        int dp[m]; // dp[i]代表到达第i不的最小步数
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i < m; i++) {
            int minStep = INT32_MAX;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < i - j) { // 步数不够跳
                    continue;
                }
                minStep = min(minStep, dp[j] + 1);
            }
            dp[i] = minStep;
        }

        for (int i = 0; i < m; i++) {
            cout << dp[i] << endl;
        }

        return dp[m - 1];
    }

    int jump2(vector<int> &nums) {
        if (nums.size() == 1) {
            return 0;
        }

        int ans = 0;
        int farthest = 0; // 当前最远的坐标，只要farthest最终能大于最后一个坐标就代表能到这个坐标
        int end = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (end == i) { // 到达检查点
                ans++;
                end = farthest;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums{1, 2};
    cout << Solution().jump2(nums) << endl;
}