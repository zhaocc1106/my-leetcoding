/**
 * 随机数索引
 *
 * 给定一个可能含有重复元素的整数数组，要求随机输出给定的数字的索引。 您可以假设给定的数字一定存在于数组中。
 * 注意：
 * 数组大小可能非常大。 使用太多额外空间的解决方案将不会通过测试。
 *
 * https://leetcode-cn.com/problems/random-pick-index/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> &nums;
public:
    Solution(vector<int> &nums) : nums(nums) {
    }

    int pick(int target) {
        int count = 1;
        int ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                if (rand() % count == 0) {
                    ans = i;
                }
                count++;
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */