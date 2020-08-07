/**
 * 打家劫舍 II
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着
 * 的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。给定一个代表每个房屋存放金额的非负整
 * 数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 *
 * https://leetcode-cn.com/problems/house-robber-ii/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int robRange(vector<int> &nums, int start, int end) {
        int dp_next_next = 0; // 保存“打劫下下个房间情况下的最值”
        int dp_next = 0; // 保存“打劫下个房间情况下的最值”
        int dp = 0; // 保存“打劫当前房间情况下的最值”
        for (int i = end; i >= start; i--) {
            dp = max(
                    nums[i] + dp_next_next, // 打劫了当前房子，打劫下下个房子
                    dp_next // 没打劫当前房子，打劫下一个房子
            );
            dp_next_next = dp_next;
            dp_next = dp;
        }
        return dp;
    }

    int rob(vector<int> &nums) {
        // 理解一下提议就是，第一个和最后一个只能保留一个，则分两块分别求，取较大者
        if (nums.size() == 1) {
            return nums[0];
        }
        return max(robRange(nums, 0, nums.size() - 2), robRange(nums, 1, nums.size() - 1));
    }
};

