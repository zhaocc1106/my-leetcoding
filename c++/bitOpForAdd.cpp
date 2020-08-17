/**
 * 不用加减乘除做加法
 *
 * 写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。
 *
 * https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int add(int a, int b) {
        int x = ~(1 << 31); // 防止负数左移
        while (b != 0) {
            int c = (a & b & x) << 1; // 进位
            a = a ^ b; // 非进位
            b = c;
        }
        return a;
    }
};