/**
 * 计数质数
 *
 * 统计所有小于非负整数 n 的质数的数量。
 *
 * https://leetcode-cn.com/problems/count-primes/
 */

#include <iostream>
#include <memory.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        bool arr[n]; // 记录n是否是质数
        memset(arr, 1, sizeof(arr));

        for (int i = 2; i * i < n; i++) {
            if (arr[i]) {
                for (int j = i * i; j < n; j += i) { // i的倍数皆不是质数
                    arr[j] = false;
                }
            }
        }

        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (arr[i]) {
                ans++;
            }
        }

        return ans;
    }
};

int main() {
    cout << Solution().countPrimes(10) << endl;
}