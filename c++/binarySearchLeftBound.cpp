/**
 * 二分查找目标值左边界
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int binarySearch(vector<int> &arr, int target) {
        if (arr.size() == 0) {
            return -1;
        }

        int right = arr.size() - 1;
        int left = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) { // 继续寻找左边界
                right = mid - 1;
            } else if (arr[mid] > target) {
                right = mid - 1;
            } else if (arr[mid] < target) {
                left = mid + 1;
            }
        }

        if (left >= 0 && left < arr.size() && arr[left] == target) {
            return left;
        }
        return -1;
    }
};

int main() {
    vector<int> arr{1, 1, 2, 2, 4, 5, 7, 9, 9};
    cout << Solution::binarySearch(arr, 4);
}