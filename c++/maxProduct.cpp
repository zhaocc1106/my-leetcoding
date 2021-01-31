/**
* 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
*
* https://leetcode-cn.com/problems/maximum-product-subarray
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // 时间复杂度较大，会超时
    int maxProduct(const vector<int>& nums) {
        int len = nums.size();

        vector<vector<int>> dp(len, vector<int>(len, INT32_MIN)); // dp[i][j]代表第i字符到j字符连乘
        int ans = INT32_MIN;

        for (int i = 1; i <= len; i++) { // 遍历所有长度
            for (int j = 0; j + i <= len; j++) { // 遍历所有其实坐标
                if (i == 1) { // 长度为1时
                    dp[j][j] = nums[j];
                    ans = max(ans, dp[j][j]);
                    continue;
                }

                dp[j][j + i - 1] = dp[j][j + i - 2] * nums[j + i - 1]; // 乘上新的值
                ans = max(ans, dp[j][j + i - 1]);
            }
        }

        return ans;
    }

    // 时间复杂度o(n)，不超时
    int maxProduct2(const vector<int>& nums) {
        int len = nums.size();

        // dp[i][0]代表前i个数组连乘的最大值，dp[i][1]代表前i个数组连乘的最小值
        vector<vector<int>> dp(len + 1, vector<int>(2, INT32_MIN));
        dp[0][0] = 1;
        dp[0][1] = 1;

        int ans = INT32_MIN;
        for (int i = 1; i <= len; i++) {
            dp[i][0] = max(nums[i - 1], // 不和前面做连乘
                           max(dp[i - 1][0] * nums[i - 1], // 前面连乘的最大值乘当前值
                               dp[i - 1][1] * nums[i - 1])); // 前面连乘最小值乘当前值（负负得正）
            dp[i][1] = min(nums[i - 1], // 不和前面做连乘
                           min(dp[i - 1][0] * nums[i - 1], // 前面连乘的最大值乘当前值（正负得负）
                               dp[i - 1][1] * nums[i - 1])); // 前面连乘最小值乘当前值
            ans = max(ans,
                      max(dp[i][0], dp[i][1]));
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    cout << Solution().maxProduct2({2, 3, -2, 4});
}