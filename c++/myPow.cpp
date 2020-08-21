/**
 * 数值的整数次方
 *
 * 实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。
 *
 * https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // 暴力解法，太耗时
    double myPow(double x, int n) {
        bool pos = n >= 0;
        n = abs(n);
        double ans = 1;
        for (int i = 1; i <= n; i++) {
            ans *= x;
        }

        return pos ? ans : 1 / ans;
    }

    // 快速幂解法
    double myPow2(double x, int n) {
        if (x == 0) {
            return 0;
        }
        if (n >= 0) {
            return power(x, n);
        } else {
            return power(1 / x, n);
        }
    }

    double power(double x, int n) {
        if (n == 0) {
            return 1;
        }

        double r = power(x, n / 2);
        if ((n & 1) == 1) { // 奇数个乘积
            return r * r * x;
        } else {
            return r * r;
        }
    }
};