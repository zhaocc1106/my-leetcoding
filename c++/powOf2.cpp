/**
 * 判断一个数是否是2的n次幂
 */

#include <iostream>

using namespace std;

class Solution {
public:
    static bool ifPowOf2(int x) {
        if (x == 0) {
            return false;
        }

        int high = 31;
        for (; high >= 0 && ((x >> high) & 1) == 0; high--); // 寻找最高位为1的位置
        int low = 0;
        for (; low < 32 && ((x >> low) & 1) == 0; low++); // 寻找最高位为1的位置
        cout << "high: " << high << ", low: " << low << endl;
        return high == low; // 如果最高位等于最低位则代表只有一位为1，且是最高位，即代表是2的n次幂
    }
};

int main() {
    cout << Solution::ifPowOf2(3) << endl;
}