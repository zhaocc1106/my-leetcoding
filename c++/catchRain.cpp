/**
 * 接雨水
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // 备忘录解法
    int trap(vector<int>& height) {
        int m = height.size();
        vector<int> lMaxVec(m, 0); // 每个柱子左边最高柱子的高度
        vector<int> rMaxVec(m, 0); // 每个柱子右边最高柱子的高度

        int lMax = 0;
        for (int i = 0; i < m; i++) {
            if (lMax < height[i]) {
                lMax = height[i];
            }
            lMaxVec[i] = lMax;
        }

        int rMax = 0;
        for (int i = m - 1; i >= 0; i--) {
            if (rMax < height[i]) {
                rMax = height[i];
            }
            rMaxVec[i] = rMax;
        }

        int ans = 0;
        for (int i = 0 ; i < m; i++) {
            ans += max(min(lMaxVec[i], rMaxVec[i]) - height[i], 0);
        }

        return ans;
    }

    // 双指针解法
    int trap2(vector<int>& height) {
        if (height.size() == 0) {
            return 0;
        }

        int left = 0;
        int right = height.size() - 1;
        int ans = 0;
        int lMax = height[left];
        int rMax = height[right];
        while (left <= right) {
            lMax = max(lMax, height[left]);
            rMax = max(rMax, height[right]);

            if (lMax < rMax) {
                ans += lMax - height[left];
                left++;
            } else {
                ans += rMax - height[right];
                right--;
            }
        }

        return ans;
    }
};

int main() {

}
