/**
 * I. 滑动窗口的最大值
 *
 * 给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
 *
 * https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/
 */

#include <iostream>
#include <vector>
#include <climits>
#include <deque>

using namespace std;

class Solution {
public:

    // 动态规划解法，比较耗时
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int m = nums.size();
        vector<vector<int>> dp(k + 1, vector<int>(m + 1, INT_MIN));

        vector<int> ans;
        for (int i = 1; i <= k; ++i) {
            for (int j = i; j <= m; j++) {
                dp[i][j] = max(dp[i - 1][j - 1], nums[j - 1]);
                // cout << dp[i][j] << ",";
                if (i == k) {
                    ans.push_back(dp[i][j]);
                }
            }
            // cout << endl;
        }

        return ans;
    }

    // 单调队列解法
    vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
        vector<int> ans; // 存储结果
        deque<int> que; // 单调队列，存储窗口种最大值的标签

        for (int i = 0; i < nums.size(); i++) {
            while (!que.empty() && nums[que.back()] < nums[i]) { // 只保留窗口的最大值的标签
                que.pop_back();
            }

            if (!que.empty() && que.front() < i - k + 1) {
                que.pop_front(); // 删除过期的最大值的标签
            }

            que.push_back(nums[i]);

            if (i >= k - 1) {
                ans.push_back(nums[que.front()]);
            }
        }

        return ans;
    }
};

