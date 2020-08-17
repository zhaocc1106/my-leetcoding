/**
 * 表示数值的字符串
 *
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"0123"都表
 * 示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。
 *
 * https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/
 */

#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string trim(string s) {
        int begin = 0;
        int end = s.length() - 1;
        for (; begin < s.length() && s[begin] == ' ' ; begin++);
        for (; end >= 0 && s[end] == ' '; end--);
        if (begin <= end) {
            return s.substr(begin, end - begin + 1);
        } else {
            return "";
        }
    }

    bool isNumber(string str) {
        bool hasPoint = false; // 是否包含.符号
        bool hasE = false; // 是否包含e

        string s = trim(str); // 去掉首尾空格
        cout << "s:" << s << endl;

        int len = s.length();

        if (len == 0) {
            return false;
        }

        // 如果只有1个字符，则必须为数字
        if (len == 1) {
            char c = s[0];
            return c >= '0' && c <= '9';
        }

        int i = 0;
        for (; i < len; i++) {
            char c = s[i];
            if (c == '+' || c == '-') { // +和-符号只能出现在第一个或者e后面第一个
                if (i == 0 || (i > 0 && (s[i - 1] == 'e' || s[i - 1] == 'E') && i != len - 1)) {
                    continue;
                } else {
                    break;
                }
            } else if (c == '.') {
                if (hasPoint) { // 不能重复包含.符号
                    break;
                }
                if (hasE) { // .符号不能在e符号后面
                    break;
                }
                if (i == 0 && (s[i + 1] == 'e' || s[i + 1] == 'E')) { // 当.符号为第一个，后面不能为e符号
                    break;
                }
                if (i == len - 1 && (s[i - 1] == '+' || s[i - 1] == '-')) { // 当.符号为最后一个，前面不能是+-符号
                    break;
                }
                hasPoint = true;
            } else if (c == 'e' || c == 'E') {
                if (hasE) { // 不能重复包含e符号
                    break;
                }
                if (i == 0 || i == len - 1) { // e不能在首尾
                    break;
                }
                if (s[i - 1] == '+' || s[i - 1] == '-') { // e前面不能是+ -符号
                    break;
                }
                hasE = true;
            } else if ((c < '0' || c > '9')) {
                return false; // 非法符号
            }
        }
        return i == len;
    }
};

int main() {
    cout << Solution().isNumber("-.8");
}