/**
 * 两数之和
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
 * https://leetcode-cn.com/problems/two-sum/
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        multimap<int, int> num2ind; // key保存数值，value保存该值对应的标签
        for (int i = 0; i < nums.size(); i++) {
            num2ind.insert(make_pair(nums[i], i));
        }

        for (int i = 0; i < nums.size(); i++) {
            int sub = target - nums[i];
            auto iter = num2ind.find(sub);
            if (iter != num2ind.end() && iter->second != i) {
                return {i, iter->second};
            }
        }

        return {-1, -1};
    }

    vector<int> twoSum2(vector<int> &nums, int value) {
        sort(nums.begin(), nums.end()); //排序

        // 双指针解法
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == value) {
                return {left, right};
            } else if (sum < value) {
                ++left;
            } else {
                --right;
            }
        }
        return {-1, -1};
    }
};

int main() {
    vector<int> nums{2, 2, 7, 11, 15};
    Solution solution;
    vector<int> res = solution.twoSum(nums, 4);
    cout << res[0] << ", " << res[1] << endl;
}

