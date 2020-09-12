/**
 * 最长连续序列
 *
 * 给定一个未排序的整数数组，找出最长连续序列的长度。
 * 要求算法的时间复杂度为 O(n)。
 *
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet;
        for (auto &num : nums) {
            numsSet.insert(num);
        }

        int maxLen = 0;
        for (auto &num : numsSet) {
            if (numsSet.count(num - 1) > 0) { // 找到连续序列的最小值
                continue;
            }
            int cur = num;
            int curLen = 1;
            while (numsSet.count(cur + 1) > 0) { // 查看当前连续序列的长度
                cur++;
                curLen++;
            }
            maxLen = max(maxLen, curLen);
        }

        return maxLen;
    }
};