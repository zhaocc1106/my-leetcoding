/**
 * 数组中的逆序对
 *
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数
 *
 * https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mergeSort(vector<int> &nums, vector<int> &tmp, int l, int r) {
        if (l >= r) {
            return 0;
        }

        // 分成两半，分别进行归并排序
        int mid = (l + r) / 2;
        int revNum = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);

        int i = l, j = mid + 1, pos = l;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[pos] = nums[i];
                i++;
                revNum += (j - (mid + 1));
            } else {
                tmp[pos] = nums[j];
                j++;
            }
            pos++;
        }

        while (i <= mid) {
            tmp[pos] = nums[i];
            i++;
            revNum += (j - (mid + 1));
            pos++;
        }

        while (j <= r) {
            tmp[pos] = nums[j];
            j++;
            pos++;
        }

        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return revNum;
    }

    int reversePairs(vector<int> &nums) {
        vector<int> tmp(nums.size()); // 用于临时保存归并排序的结果
        return mergeSort(nums, tmp, 0, nums.size() - 1);
    }
};

int main() {
    vector<int> nums = {1, 3, 2, 3, 1, 6, 8, 7, 5};
    cout << Solution().reversePairs(nums) << endl;
    for (auto num : nums) {
        cout << num << ", ";
    }
}