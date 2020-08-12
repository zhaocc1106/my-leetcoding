/**
 * 把数字翻译成字符串
 *
 * 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多
 * 个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
 *
 * https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        vector<int> dp(n + 1, 0); // 动态规划，每个元素代表前几个元素选择完之后最多的翻译方式
        dp[0] = 1;
        dp[1] = 1; // 第一个元素可选择的翻译方式只有一种

        for (int i = 2; i <= n; i++) {
            if (numStr[i - 2] == '1' ||
                (numStr[i - 2] == '2' && numStr[i - 1] <= '5')) { // 如果前一个元素为1或者前一个元素为2，并且当前元素小于等于5，则有两种翻译方式
                dp[i] = dp[i - 1] // 当前元素只选择独立自己翻译
                        + dp[i - 2]; // 当前元素和前一个元素联合翻译
            } else {
                dp[i] = dp[i - 1]; // 当前元素只能选择自己独立翻译
            }
        }

        /*for (auto i : dp) {
            cout << i << ", ";
        }
        */

        return dp[n];
    }

    int translateNum2(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        int pre2 = 1; // 当前元素往前移动两个位置为截止元素的最多翻译方式
        int pre1 = 1; // 当前元素往前移动一个位置为截止元素的最多翻译方式
        int dp = 0; // 当前元素为截止，最多翻译方式

        for (int i = 2; i <= n; i++) {
            if (numStr[i - 2] == '1' ||
                (numStr[i - 2] == '2' && numStr[i - 1] <= '5')) { // 如果前一个元素为1或者前一个元素为2，并且当前元素小于等于5，则有两种翻译方式
                dp = pre1 // 当前元素只选择独立自己翻译
                     + pre2; // 当前元素和前一个元素联合翻译
            } else {
                dp = pre1; // 当前元素只能选择自己独立翻译
            }
            pre2 = pre1;
            pre1 = dp;
        }

        return dp;
    }
};

int main() {
    cout << Solution().translateNum2(1111);
}