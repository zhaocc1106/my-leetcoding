/**
* 获取一个正整数数组的最优跳动方式
*
* 从数组中间的任意位置开始向右跳，每次跳动的步伐数不能超过该位置对应元素的值，在跳动次数最少的情况下计算每次跳动的步伐
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void recur(vector<int>& dp, const vector<int>& arr, int pos) {
        if (pos >= dp.size() - 1) {
            // 当前已经跳过最后一个元素，不用再跳，直接返回
            dp[pos] = 0;
            return;
        }

        if (dp[pos] != -1) {
            // 如果该位置最小跳动步数已经计算过，则直接返回
            return;
        }

        int min_step = INT32_MAX;
        for (int s = 1; s <= arr[pos]; s++) { // 遍历每种跳动的可能
            recur(dp, arr, pos + s); // 递归计算该位置的最小跳动次数
            min_step = min(min_step, dp[pos + s]);
        }
        dp[pos] = min_step + 1;
    }

public:
    vector<int> min_steps(const vector<int>& arr) {
        int size = arr.size();
        if (size == 0) {
            return {};
        }

        vector<int> dp(size, -1);
        recur(dp, arr, 0);

        return dp;
    }
};

int main(int argc, char** argv) {
    vector<int> arr = {1, 3, 2, 1, 1, 1};
    vector<int> steps = Solution().min_steps(arr);

    for (int& step: steps) {
        cout << step << ",";
    }
}
