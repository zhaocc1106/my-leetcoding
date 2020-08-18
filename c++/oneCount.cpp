/**
 * 1～n整数中1出现的次数
 *
 * 输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。
 * 例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。
 *
 * https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int oneCount(int n) {
        int count = 0;
        while (n > 0) {
            if (n % 10 == 1) {
                count++;
            }
            n = n / 10;
        }
        return count;
    }

    // 暴力解法，会超时
    int countDigitOne(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            count += oneCount(i);
        }
        return count;
    }

    // 找数学规律
    int countDigitOne2(int n) {
        long i = 1; // i用于表示当前是10进制的第几位，1、10、100、***10^31，所以用long来记录
        int ans = 0;
        while (n / i) { // 计算每一位上出现10的次数
            int cur = (n / i) % 10; // 当前位的数值
            int high = (n / i) / 10; // 高位的数值
            int low = n - (n / i) * i; // 低位的数值
            if (cur == 0) {
                ans += high * i;
            } else if (cur == 1) {
                ans += high * i + low + 1;
            } else {
                ans += high * i + i;
            }
            i *= 10;
        }
        return ans;
    }
};

int main() {

}