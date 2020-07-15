/**
 * https://leetcode-cn.com/problems/next-permutation/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static void nextPermutation(vector<int> &nums) {
        int size = nums.size();
        if (size == 1) {
            return;
        }

        bool hasBigger = false;

        // 寻找第一组相邻元素右边比左边大的组合
        int swapR = nums.size() - 1;
        for (; swapR > 0; swapR--) {
            if (nums[swapR] > nums[swapR - 1]) {
                hasBigger = true;
                break;
            }
        }
        cout << "swapR: " <<  swapR << endl;
        if (hasBigger) {
            int swapL = swapR - 1;
            for (int i = swapR + 1; i < nums.size(); i++) {
                if (nums[i] < nums[swapR] && nums[i] > nums[swapL]) {
                    swapR = i;
                }
            }
            cout << "swapL: " << swapL << ", swapR: " << swapR << endl;

            // 交换
            int tmp = nums[swapL];
            nums[swapL] = nums[swapR];
            nums[swapR] = tmp;

            // 将swapL右侧排一下序
            sort(nums.begin() + swapL + 1, nums.end());
        } else {
            cout << "No bigger" << endl;

            // 没有更大的队列，逆序整个队列
            reverse(nums.begin(), nums.end());
            /*
            for (int i = 0; i < size / 2; i++) {
                if (nums[i] != nums[size - i - 1]) {
                    int tmp = nums[i];
                    nums[i] = nums[size - i - 1];
                    nums[size - i - 1] = tmp;
                }
            }
            */
        }
    }
};

int main() {
    vector<int> v{3, 2, 1};
    cout << "Origin: " << endl;
    for (auto item : v) {
        cout << item << ", ";
    }
    cout << endl;
    Solution::nextPermutation(v);
    for (auto item : v) {
        cout << item << ", ";
    }
    cout << endl;
}