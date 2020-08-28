/**
 * 缺失数字
 *
 * 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
 *
 * https://leetcode-cn.com/problems/missing-number/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        ans ^= nums.size();
        for (int i = 0; i < nums.size(); i++) {
            ans ^= (i ^ nums[i]);
        }

        return ans;
    }
};