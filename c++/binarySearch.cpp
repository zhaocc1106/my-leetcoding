/**
 * https://leetcode-cn.com/problems/binary-search/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int search(vector<int> nums, int target) {
        int len = nums.size();
        int left = 0; // 搜索范围起始位
        int right = nums.size() - 1; // 搜索范围终止位
        while (left <= right) {
            int mid = (right + left) / 2; // 搜索范围中间值
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> arr {-1, 0, 3, 5, 6};
    cout << Solution::search(arr, 2);
}