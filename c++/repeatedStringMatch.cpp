/**
 * 重复叠加字符串匹配
 *
 * 给定两个字符串 a 和 b，寻找重复叠加字符串 a 的最小次数，使得字符串 b 成为叠加后的字符串 a 的子串，如果不存在则返回 -1。
 *
 * 注意：字符串 "abc" 重复叠加 0 次是 ""，重复叠加 1 次是 "abc"，重复叠加 2 次是 "abcabc"。
 *
 * https://leetcode-cn.com/problems/repeated-string-match/
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if (a.length() == 0 || b.length() == 0) {
            return -1;
        }

        int ans = 0;
        int maxRep = b.length() / a.length() + 2; // 最大重复次数为b / a + 2

        string tmp = ""; // 存储a重复生成的字符串
        while (tmp.find(b) == string::npos) { // 如果当前a重复生成的字符串不包含b
            if (ans == maxRep) { // 当前重复次数已经是最大，直接返回
                return -1;
            }
            tmp += a;
            ans++;
        }

        return ans;
    }
};

int main() {
    cout << Solution().repeatedStringMatch("abcd", "cdabcdab") << endl;
}