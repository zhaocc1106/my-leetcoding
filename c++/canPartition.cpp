/**
 * 分割等和子集
 *
 * 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 注意:
 * 每个数组中的元素不会超过 100
 * 数组的大小不会超过 200
 * https://leetcode-cn.com/problems/partition-equal-subset-sum/
 */

#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0; // 记录整个数组的sum
        for_each(nums.begin(), nums.end(), [&sum](int item) {
            sum += item;
        });
        cout << "sum: " << sum << endl;

        // 寻找是否存在一个子集和等于整个数组sum的一半，则就是存在两个数组和相等

        if (sum % 2 != 0) {
            // 如果和为奇数，则直接判定为不存在
            return false;
        }

        int partSum = sum / 2;
        bool dp[nums.size() + 1][partSum + 1]; // 第一维代表所有数的选择，第二维代表所有和，元素值代表当前状态下，当前和是否存在
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= nums.size(); i++) {
            dp[i][0] = true; // 如果当前和为0
        }
        for (int j = 0; j <= partSum; j++) {
            dp[0][j] = false; // 如果没有选择任何数字，则所有和情况都不存在
        }

        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= partSum; j++) {
                dp[i][j] = (j - nums[i - 1] >= 0 && dp[i - 1][j - nums[i - 1]]) // 选择当前数字
                        || dp[i - 1][j]; // 不选择当前数字
                if (j == partSum && dp[i][j]) {
                    return true;
                }
            }
        }

        return false;
    }
};


int main() {
    vector<int> nums{1, 5, 11, 5};
    cout << Solution().canPartition(nums);
}