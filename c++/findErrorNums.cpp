/**
 * 错误的集合
 *
 * 集合 S 包含从1到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个元素复制了成了集合里面的另外一个元素的值，导致集合丢失了一个
 * 整数并且有一个元素重复。
 * 给定一个数组 nums 代表了集合 S 发生错误后的结果。你的任务是首先寻找到重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
 *
 * https://leetcode-cn.com/problems/set-mismatch/
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i]) - 1] > 0) {
                nums[abs(nums[i]) - 1] *= -1;
            } else {
                ans.push_back(abs(nums[i]));
            }
        }

        // for (int num : nums) {
        //     cout << num << ", ";
        // }
        // cout << endl;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};