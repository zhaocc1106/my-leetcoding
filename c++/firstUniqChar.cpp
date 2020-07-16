/**
 * https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/
 */

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    static char firstUniChar(string str) {
        unordered_set<char> chars;
        for (int i = 0; i < str.length(); i++) {
            if (chars.count(str[i])) { // 防止重复判断某个字符
                continue;
            }

            int j = 0;
            for (; (j == i || str[j] != str[i]) && j < str.length(); j++);
            if (j == str.length()) {
                return str[i];
            }

            chars.insert(str[i]);
        }
        return ' ';
    }
};
