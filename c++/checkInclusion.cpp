/**
 * 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列
 * https://leetcode-cn.com/problems/permutation-in-string/
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> window; // 存放滑动窗口包含某些字符的数量
        unordered_map<char, int> needs; // 存放所有需要包含的字符
        for (auto &item : s1) {
            needs[item]++;
        }

        int match = 0; // 当前窗口里包含了多少必须包含的字符
        int left = 0; // 存放窗口左边界
        int right = 0; // 存放窗口右边界

        while (right < s2.size()) {
            char curR = s2[right];
            if (needs.count(curR) > 0) { // 当前字符是需要包括的
                window[curR]++;
                if (window[curR] == needs[curR]) { // 当前窗口里对于某个必须字符个数已经足够
                    match++;
                }
            }

            if (match == needs.size()) { // 如果当前窗口已经包含了所有必须包含的字符
                while (left <= right) {
                    int windowLen = right - left + 1; // 当前滑动窗口长度
                    // 如果当前滑动窗口长度和关键字符总个数一致，则说明窗口内不包含其他非关键字符，即当前窗口是排列
                    if (windowLen == s1.size()) {
                        return true;
                    }

                    char curL = s2[left];
                    if (needs.count(curL) > 0) { // 当前字符是需要包括的
                        window[curL]--;
                        if (window[curL] < needs[curL]) {
                            match--; // 有一个字符不满足
                            left++;
                            break;
                        }
                    }
                    left++;
                }
            }
            right++;
        }
        return false;
    }

    static bool checkInclusion2(string s1, string s2) {
        // 存放窗口当前包含关键字符的情况,value对应当前缺几个字符，0代表该字符全了，负数代表该字符多了
        unordered_map<char, int> needs;
        for (auto &item : s1) {
            needs[item]++;
        }

        int match = 0; // 当前窗口里包含关键字符满足需求的个数
        int left = 0; // 存放窗口左边界
        int right = 0; // 存放窗口右边界

        while (right < s2.size()) {
            char curR = s2[right];
            if (needs.count(curR) > 0) { // 当前字符是需要包括的
                needs[curR]--;
                if (needs[curR] == 0) { // 当前窗口里对于某个必须字符个数已经足够
                    match++;
                }
            }

            if (match == needs.size()) { // 如果当前窗口已经包含了所有必须包含的字符
                while (left <= right) {
                    int windowLen = right - left + 1; // 当前滑动窗口长度
                    // 如果当前滑动窗口长度和关键字符总个数一致，则说明窗口内不包含其他非关键字符，即当前窗口是排列
                    if (windowLen == s1.size()) {
                        return true;
                    }

                    char curL = s2[left];
                    if (needs.count(curL) > 0) { // 当前字符是需要包括的
                        needs[curL]++; // 左边界移除，该关键字符仍所需个数加一
                        if (needs[curL] > 0) {
                            match--; // 有一个字符不满足
                            left++;
                            break;
                        }
                    }
                    left++;
                }
            }
            right++;
        }
        return false;
    }
};

int main() {
    cout << Solution::checkInclusion("abce", "eidabbcaooo");
}