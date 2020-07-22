/**
 * Rotation binary search.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int rotationBinSearch(const vector<int> &arr, int key) {
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high) {
            int mid = (high + low) / 2;
            cout << "low: " << low << ", mid: " << mid << ", high: " << high << endl;
            if (arr[mid] == key) {
                return mid;
            }
            if (arr[low] <= arr[mid]) { // 左侧有序
                if (key >= arr[low] && key < arr[mid]) { // 如果这个值在左侧里
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else { // 右侧有序
                if (key <= arr[high] && key > arr[mid]) { // 如果这个值在右侧里
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<int> arr {7, 8, 9, 1, 2, 3, 4};
    cout << Solution::rotationBinSearch(arr, 5) << endl;
}
