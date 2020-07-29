/**
 * 找到字符串中所有字母异位词
 * https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    static vector<int> findAnagrams(string s, string p) {
        if (s.size() == 0) {
            return {};
        }

        unordered_map<char, int> window; // 存放滑动窗口包含某些字符的数量
        unordered_map<char, int> needs; // 存放所有需要包含的字符
        for (auto item : p) {
            needs[item]++;
        }

        int match = 0; // 当前窗口里包含了多少必须包含的字符
        int left = 0; // 存放窗口左边界
        int right = 0; // 存放窗口右边界
        vector<int> ans; // 保存所有符合要求的子串起始位置

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
                    if (right - left + 1 == p.size()) { // 如果子串长度和目标字符串长度一致，则加入到结果中
                        ans.push_back(left);
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
        return ans;
    }
};

int main() {
    auto ans = Solution::findAnagrams("cbaebabacd", "abc");
    for_each(ans.begin(), ans.end(), [](int i) {
       cout << i << ",";
    });
}