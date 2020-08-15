/**
* 正则表达式匹配
*
* 请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
* 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。
*
* https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/
*/

#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.length() == 0) { // 匹配为空
            return s.length() == 0;
        }
        bool firstMatch = (s.length() > 0) && (s[0] == p[0] || p[0] == '.'); // 第一个字符是否匹配

        if (p.length() >= 2 && p[1] == '*') {
            return (isMatch(s, p.substr(2))) // 跳过前面的?*，?为任意字符或.
                   || (firstMatch && isMatch(s.substr(1), p)); // 第一个字符匹配，则匹配字符串的?*这两个可以继续用
        } else {
            return firstMatch && isMatch(s.substr(1), p.substr(1)); // 字符串与匹配各前进一步
        }
    }

    bool isMatch2(string s, string p) {
        int m = s.length();
        int n = p.length();

        // lambda 表达式代表当前字符是否匹配
        auto match = [&](int i, int j) {
            if (i == 0) { // 如果字符串为空
                return false;
            }

            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                return true;
            }
            return false;
        };

        int f[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = true; // 如果字符串和正则都为空则匹配成功
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') { // 如果当前匹配符是*符号
                    f[i][j] |= f[i][j - 2]; // 当前字符和上一个匹配符不匹配，跳过两个匹配符号，即*代表0次
                    if (match(i, j - 1)) { // 当前字符和上一个匹配符匹配，*代表至少一次
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else { // 如果当前匹配不是*符号，则只判断当前一个字符
                    if (match(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};

int main() {
    cout << Solution().isMatch2("aa", "a");
}