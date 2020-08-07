/**
 * 打家劫舍
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间
 * 相邻的房屋在同一晚上被小偷闯入，系统会自动报警。给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够
 * 偷窃到的最高金额。
 * https://leetcode-cn.com/problems/house-robber/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subRob(int start, vector<int> &nums, vector<int> &dp) {
        if (start >= nums.size()) {
            // 如果没有房间再打劫，则直接返回
            return 0;
        }

        if (dp[start] != -1) {
            // 已经存在“以当前房子开始偷后的最大值”, 不需要做重复动作
            return dp[start];
        }

        dp[start] = max(
                nums[start] + subRob(start + 2, nums, dp), // 打劫了当前房子，去打劫下下家
                subRob(start + 1, nums, dp) // 不打劫当前房子，去打劫了下一家房子情况下的最大值
        );
        return dp[start];
    }

    /* 自顶向下的动态规划解法 */
    int rob(vector<int> &nums) {
        vector<int> dp(nums.size(), -1); // 用于保存“如果打劫了当前的房子情况下的最大值”，初始值全部为-1
        return subRob(0, nums, dp);
    }

    /* 自底向上的动态规划解法 */
    int rob2(vector<int> &nums) {
        vector<int> dp(nums.size() + 2, 0); // 用于保存“如果打劫了当前的房子情况下的最大值”，初始值全部为0
        for (int i = nums.size() - 1; i >= 0; i--) {
            dp[i] = max(
                    nums[i] + dp[i + 2], // 打劫了当前房子，打劫下下个房子
                    dp[i + 1] // 没打劫当前房子，打劫下一个房子
                    );
        }
        return dp[0];
    }

    /* 自底向上的动态规划解法，不使用容器 */
    int rob3(vector<int> &nums) {
        int dp_next_next = 0; // 保存“打劫下下个房间情况下的最值”
        int dp_next = 0; // 保存“打劫下个房间情况下的最值”
        int dp = 0; // 保存“打劫当前房间情况下的最值”
        for (int i = nums.size() - 1; i >= 0; i--) {
            dp = max(
                    nums[i] + dp_next_next, // 打劫了当前房子，打劫下下个房子
                    dp_next // 没打劫当前房子，打劫下一个房子
            );
            dp_next_next = dp_next;
            dp_next = dp;
        }
        return dp;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1, 2, 3, 1};
    cout << solution.rob3(nums);
}