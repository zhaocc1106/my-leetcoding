/**
 * 柱状图中最大的矩形
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 *
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 *
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // 枚举左右边界的解法，超时
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        if (n == 0) {
            return 0;
        }
        int ans = heights[0];
        for (int i = 0; i < n; i++) {
            int minHeight = heights[i]; // 记录以当前位置为左边界的最小高度
            for (int j = i; j < n; j++) {
                minHeight = min(minHeight, heights[j]);
                ans = max(ans, (j - i + 1) * minHeight);
            }
        }
        return ans;
    }

    // 枚举攻读的解法，使用单调栈存储每个高度的左右边界
    int largestRectangleArea2(vector<int> &heights) {
        int n = heights.size();
        if (n == 0) {
            return 0;
        }

        stack<pair<int, int>> lStack; // 单调栈协助寻找左边界
        vector<int> lBuf(n, 0); // 存放每个高度的左边界
        stack<pair<int, int>> rStack; // 单调栈协助寻找右边界
        vector<int> rBuf(n, n - 1); // 存放每个高度的右边界
        for (int i = 0; i < n; i++) { // 遍历所有的高度
            // 寻找左边界，即寻找左边最近的并且比当前高度小的位置
            int left = i;
            while (!lStack.empty() && lStack.top().first >= heights[i]) {
                lStack.pop();
            }
            if (!lStack.empty()) { // 在单调栈种找到了左边界
                left = lStack.top().second;
            } else {
                left = -1;
            }
            lStack.push(make_pair(heights[i], i));
            lBuf[i] = left;
        }
        for (int i = 0; i < n; i++) {
            cout << lBuf[i] << ",";
        }
        cout << endl;

        for (int i = n - 1; i >= 0; i--) { // 遍历所有的高度
            // 寻找右边界，即寻找右边最近的并且比当前高度小的位置
            int right = i;
            while (!rStack.empty() && rStack.top().first >= heights[i]) {
                rStack.pop();
            }
            if (!rStack.empty()) { // 在单调栈种找到了左边界
                right = rStack.top().second;
            } else {
                right = n;
            }
            rStack.push(make_pair(heights[i], i));
            rBuf[i] = right;
        }
        for (int i = 0; i < n; i++) {
            cout << rBuf[i] << ",";
        }
        cout << endl;

        int maxArea = 0;
        for (int i = 0; i < n; i++) { // 遍历所有的高度
            // 计算每个坐标对应的矩形的面积
            maxArea = max(maxArea, (rBuf[i] - lBuf[i] - 1) * heights[i]);
        }
        return maxArea;
    }
};

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << Solution().largestRectangleArea2(heights);
}