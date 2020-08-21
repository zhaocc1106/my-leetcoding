/**
 * 数字序列中某一位的数字
 *
 * 数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
 * 请写一个函数，求任意第n位对应的数字。
 *
 * https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1; // 表示当前组包含多少位，比如0-9的digit是1，10-99的digit为2，100-999的digit为3
        long long start = 1; //表示当前组的其实值，比如0-9的起始值为0，10-99的起始值为10，100-999的起始值为100
        long long count = 9; // 表示当前组的容量，比如0-9的容量为9，10-99的容量为90，100-999的容量为900

        while (n > count) { // 先找到该数属于哪一组
            n -= count;
            digit++;
            start *= 10;
            count = digit * start * 9;
        }

        long long number = start + (n - 1) / digit; // 找到n所在的那个数字
        string numStr = to_string(number);
        return numStr[(n - 1) % digit] - '0'; // 找到n所在该数字的第几位
    }
};