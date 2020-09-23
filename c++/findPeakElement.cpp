/**
 * 峰值元素是指其值大于左右相邻值的元素。
 *
 * 给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。
 *
 * 数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
 *
 * 你可以假设 nums[-1] = nums[n] = -∞。
 *
 *
 * https://leetcode-cn.com/problems/find-peak-element/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int recur(vector<int> &nums, int l, int h) {
        if (l > h) {
            return -1;
        }

        if (l == h) {
            if (l == -1 || l == nums.size()) {
                return -1;
            }
        }

        int mid = (l + h) / 2;
        // cout << "l: " << l << ", h: " << h << ", mid: " << mid << endl;
        bool bigThanLeft = mid == 0 ? true : nums[mid] > nums[mid - 1]; // 比左值大
        bool bigThanRight = mid == nums.size() - 1 ? true : nums[mid] > nums[mid + 1]; // 比右值大

        if (bigThanLeft && bigThanRight) {
            return mid;
        } else {
            int ind = recur(nums, l, mid - 1);
            if (ind >= 0) {
                return ind;
            }
            ind = recur(nums, mid + 1, h);
            if (ind >= 0) {
                return ind;
            }
            return -1;
        }
    }

    int findPeakElement(vector<int>& nums) {
        return recur(nums, -1, nums.size());
    }
};