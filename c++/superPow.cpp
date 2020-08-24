/**
 * 超级次方
 *
 * 你的任务是计算 a^b 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。
 *
 * https://leetcode-cn.com/problems/super-pow/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int power(int a, vector<int> &b, int start) {
        if (a <= 1) {
            return a;
        }

        int m = b.size();
        bool ifOdd = (b[m - 1] % 2 == 1); // 表示当前幂是否是奇数
        bool ignoreZero = true; // 忽略前面的0

        if (start >= m) { // 当前幂已经为0
            return 1;
        }

        // 计算幂的一半的数组
        int digit = 0; // 表示上一位的余数
        for (int i = start; i < m; i++) {
            if (ignoreZero && b[i] == 0) {
                start++; // 跳过开头的0
                continue;
            } else if (b[i] != 0) {
                ignoreZero = false;
            }

            cout << b[i] << ",";

            int cur = b[i];
            if (digit != 0) {
                cur = digit * 10 + cur;
            }
            b[i] = cur / 2;
            digit = cur % 2;
        }
        cout << endl;
        cout << "ifOdd: " << ifOdd << endl;

        a %= 1337;
        int sub = power(a, b, start) % 1337;
        if (ifOdd) {
            return a * sub % 1337 * sub % 1337; // 如果为奇数幂，则结果应该是a^(b / 2) * a^(b / 2) * a
        } else {
            return sub % 1337 * sub % 1337; // 如果为偶数，结果应该是a^(b / 2) * a^(b / 2)
        }
    }

    int superPow(int a, vector<int> &b) {
        return power(a, b, 0);
    }
};

int main() {
    vector<int> b{1, 0};
    cout << Solution().superPow(2, b);
}