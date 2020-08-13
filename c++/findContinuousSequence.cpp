/**
 * II. 和为s的连续正数序列
 *
 * 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
 * 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
 *
 * https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        // 滑动窗口解法
        if (target < 3) {
            return {};
        }

        vector<vector<int>> ans;

        int l = 1; // 滑动窗口左边界
        int r = 2; // 滑动窗口右边界

        int sum = 3;
        while (l < target) {
            while (sum <= target) { // 右移右边界直到窗口大于目标值，将其中和等于目标值的窗口记录下来
                if (sum == target) {
                    vector<int> wind;
                    for (int i = l; i <= r; i++) {
                        wind.push_back(i);
                    }
                    ans.push_back(wind);
                }
                r++; // 右边界右移
                sum += r;
            }
            while (sum >= target && l < r) { // 右移左边界直到窗口和小于目标值，将其中和等于目标值的窗口记录下来
                if (sum == target) {
                    vector<int> wind;
                    for (int i = l; i <= r; i++) {
                        wind.push_back(i);
                    }
                    ans.push_back(wind);
                }
                sum -= l; // 左边界右移
                l++;
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> ans = Solution().findContinuousSequence(10);
    for (auto arr : ans) {
        for (auto i : arr) {
            cout << i << ", ";
        }
        cout << endl;
    }
}