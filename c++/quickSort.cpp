/**
 * Quick sort
 * https://blog.csdn.net/weixin_42109012/article/details/91645051
 */

#include <iostream>

using namespace std;

class Solution {
public:
    static void qSort(int arr[], int low, int high) {
        if (low >= high) {
            return;
        }

        int key = arr[low];
        int i = low;
        int j = high;
        while (i < j) {
            while (i < j && arr[j] >= key) {
                j--;
            }
            if (i < j) {
                arr[i] = arr[j];
            }
            while (i < j && arr[i] <= key) {
                i++;
            }
            if (i < j) {
                arr[j] = arr[i];
            }
        }
        arr[i] = key;

        qSort(arr, low, i - 1);
        qSort(arr, i + 1, high);
    }
};

int main() {
    int arr[] = {4, 2, 5, 1};
    cout << sizeof(arr) / sizeof(int) << endl;
    Solution::qSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        cout << arr[i];
    }
    cout << endl;
}