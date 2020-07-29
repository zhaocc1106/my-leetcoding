/**
 * 最小覆盖子串
 * https://leetcode-cn.com/problems/minimum-window-substring/
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static string minWindow(string s, string t) {
        unordered_map<char, int> window; // 存放滑动窗口包含某些字符的数量
        unordered_map<char, int> needs; // 存放所有需要包含的字符
        for (auto item : t) {
            needs[item]++;
        }

        int match = 0; // 当前窗口里包含了多少必须包含的字符
        int left = 0; // 存放窗口左边界
        int right = 0; // 存放窗口右边界
        int subBegin = 0; // 存放最小子串起始位置
        int minLen = s.size() + 1; // 最小子串长度

        while(right < s.size()) {
            char curR = s[right];
            // cout << "curR: " << curR << endl;
            if (needs.count(curR) > 0) { // 当前字符是需要包括的
                window[curR]++;
                if (window[curR] == needs[curR]) { // 当前窗口里对于某个必须字符个数已经足够
                    match++;
                }
            }
            if (match == needs.size()) { // 如果当前窗口已经包含了所有必须包含的字符
                while (left <= right) {
                    // cout << "before, subBegin: " << subBegin << ", minLen: " << minLen << endl;
                    if (right - left + 1 < minLen) {
                        minLen = right - left + 1;
                        subBegin = left;
                        // cout << "after, subBegin: " << subBegin << ", minLen: " << minLen << endl;
                    }
                    char curL = s[left];
                    // cout << "curL: " << curL << endl;
                    if (needs.count(curL) > 0) { // 当前字符是需要包括的
                        window[curL]--;
                        // cout << "window[curL]: " << window[curL] << ", needs[curL]: " << needs[curL] << endl;
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
        // cout << "subBegin: " << subBegin << ", minLen: " << minLen << endl;
        return minLen > s.size() ? "" : s.substr(subBegin, minLen);
    }
};

int main() {
    // cout << Solution::minWindow("ADOBECODEBANC", "ABC");
    cout << Solution::minWindow("A", "B");
}