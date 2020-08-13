/**
 * 连续子数组的最大和
 *
 * 输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
 * 要求时间复杂度为O(n)。
 *
 * https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = INT32_MIN;
        int ans = INT32_MIN;
        for (int i = 1; i <= n; i++) {
            if (dp[i - 1] <= 0) {
                dp[i] = nums[i - 1]; // 不和前面连接
            } else {
                dp[i] = nums[i - 1] + dp[i - 1]; // 和前面做连接X
            }
            ans = max(ans, dp[i]);
        }
        for (auto i : dp) {
            cout << i << ",";
        }
        cout << endl;
        return ans;
    }

    int maxSubArray2(vector<int> &nums) {
        int n = nums.size();
        int pre = INT32_MIN; // 保存当前元素的前一个位置为终止的最大值
        int ans = INT32_MIN;
        for (int i = 1; i <= n; i++) {
            pre = pre <= 0 ? nums[i - 1] :  // 不和前面连接
                  nums[i - 1] + pre; // 和前面做连接X
            ans = max(ans, pre);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << Solution().maxSubArray2(nums);
}