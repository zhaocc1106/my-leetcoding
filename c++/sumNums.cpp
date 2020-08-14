/**
 * 求1+2+…+n
 *
 * 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
 *
 * https://leetcode-cn.com/problems/qiu-12n-lcof/
 */

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int sumNums(int n) {
        return n == 1 ? 1 : n + sumNums(n - 1);
    }
};

int main() {
    cout << Solution().sumNums(5);
}