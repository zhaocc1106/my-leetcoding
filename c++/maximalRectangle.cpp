/**
 * 最大矩形
 *
 * 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 *
 * https://leetcode-cn.com/problems/maximal-rectangle/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();

        vector<int> height(n, 0); // 记录当前坐标点所在矩形的最大高度
        vector<int> left(n, 0); // 记录当前坐标点所在矩形的最左侧的边界，矩形包含左边界
        vector<int> right(n, n); // 记录当前坐标点所在矩形的最右侧的边界，矩形不包含右边界

        int ans = 0;
        for (int i = 0; i < m; i++) { // 遍历所有行
            // 求当前行所有坐标点的所在矩形的最大高度
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    height[j] += 1;
                } else {
                    height[j] = 0;
                }
            }

            // 求当前行所有坐标点所在矩形的最左边边界
            int curLeft = 0;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], curLeft); // 需要比较当前行左侧边界与上面的行的左侧边界，选择较大者
                } else {
                    left[j] = 0; // 如果当前坐标为‘0’，可以确定高度已经为0,此时左边界已经无意义，但是对于下一行当前列左边界需要从0开始比较
                    curLeft = j + 1; // 左侧边界必须在‘0’右侧
                }
            }

            // 求当前行所有坐标点所在矩形的最右侧边界
            int curRight = n;
            for (int j = n -1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], curRight); // 需要比较当前行右侧边界与上面行的右侧边界，取较小者
                } else {
                    right[j] = n; // 当前坐标为‘0’，可以确定高度已经为0，此时右边界已经无意义，但是对于下一行当前列右边界需要从n开始比较
                    curRight = j;
                }
            }

            // 求当前行所有坐标点所在矩形的面积大小
            for (int j = 0; j < n; j++) {
                ans = max(ans, (right[j] - left[j]) * height[j]);
            }
        }

        return ans;
    }
};