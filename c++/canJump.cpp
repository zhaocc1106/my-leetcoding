/**
 * 跳跃游戏
 *
 * 给定一个非负整数数组，你最初位于数组的第一个位置。
 *
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 *
 * 判断你是否能够到达最后一个位置。
 *
 * https://leetcode-cn.com/problems/jump-game/
 */
#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

class Solution {
public:
    // 贪心算法
    bool canJump1(vector<int> &nums) {
        if (nums.size() == 1) {
            return true;
        }

        int farthest = 0; // 当前最远的坐标，只要farthest最终能大于最后一个坐标就代表能到这个坐标
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            cout << farthest << endl;
            if (farthest <= i) { // 当前坐标跳步为0，不能动了
                return false;
            }
        }
        return farthest >= nums.size() - 1;
    }
};
