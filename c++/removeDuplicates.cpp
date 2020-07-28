/**
 * 删除排序数组中的重复项
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static int removeDuplicates(vector<int> &nums) {
        /*
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size();) {
                if (nums[j] == nums[i]) {
                    nums.erase(nums.begin() + j);
                } else {
                    j++;
                }
            }
        }
        return nums.size();
        */
        if (nums.size() == 0) {
            return 0;
        }

        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }

    static int showAll(vector<int>::iterator begin, vector<int>::iterator end) {
        /*
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << endl;
        }
        for (int num : nums) {
            cout << num << endl;
        }
        */
        while (begin != end) {
            cout << *begin;
            begin++;
        }
        cout << endl;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 2, 3, 2};
    cout << "nums len: " << nums.size() << endl;
    cout << "before sort: " << endl;
    Solution::showAll(nums.begin(), nums.end());
    sort(nums.begin(), nums.end()); // 排序
    cout << "after sort: " << endl;
    Solution::showAll(nums.begin(), nums.end());
    int newLen = Solution::removeDuplicates(nums);
    cout << "after remove: " << endl;
    Solution::showAll(nums.begin(), nums.begin() + newLen);
    return 0;
}