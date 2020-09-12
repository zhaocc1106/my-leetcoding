/**
 * 每日温度
 *
 * 请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，
 * 请在该位置用 0 来代替。
 *
 * 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。
 *
 * 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
 *
 * https://leetcode-cn.com/problems/daily-temperatures/
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &T) {
        stack<pair<int, int>> sta; // 单调栈，其中每个元素是pair，first代表温度值，second代表在列表种的位置
        int n = T.size();
        vector<int> ans(n, 0); // 存放结果
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                ans[i] = 0;
                sta.push(make_pair(T[i], i)); // 最后一个温度值与位置直接放入单调栈
            } else {
                while (!sta.empty()) {
                    if (sta.top().first <= T[i]) { // 如果栈顶元素比当前值小，则出栈，保证栈单调性
                        sta.pop();
                    } else {
                        break;
                    }
                }
                int step = !sta.empty() ? sta.top().second - i : 0; // 如果栈顶元素比当前值大，则计算步数
                ans[i] = step;
                sta.push(make_pair(T[i], i)); // 当前值和位置放入栈顶
            }
        }
        return ans;
    }
};

int main() {
    vector<int> T{73, 74, 75, 71, 69, 72, 76, 73};
    Solution().dailyTemperatures(T);
}