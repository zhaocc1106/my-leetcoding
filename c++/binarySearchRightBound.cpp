/**
 * 二分查找目标值右边界
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
            if (arr[mid] == target) { // 继续寻找右边界
                left = mid + 1;
            } else if (arr[mid] > target) {
                right = mid - 1;
            } else if (arr[mid] < target) {
                left = mid + 1;
            }
        }

        if (right >= 0 && right < arr.size() && arr[right] == target) {
            return right;
        }
        return -1;
    }
};

int main() {
    vector<int> arr{1, 1, 2, 2, 4, 5, 7, 9, 9};
    cout << Solution::binarySearch(arr, 9);
}