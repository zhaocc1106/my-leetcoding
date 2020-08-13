/**
 * 无重复字符的最长子串
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
 */

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    static int lenOfLongestSubstring(string str) {
        unordered_set<char> set; // 记录某一个char是否存在
        int rk = -1; // 右边界
        int ans = 0;
        for (int i = 0; i < str.length(); ++i) {
            if (i != 0) { // 左边界移动，移除之前的左边界
                set.erase(str[i - 1]);
            }
            while (rk + 1 < str.length() && !set.count(str[rk + 1])) { // 如果右边界当前元素不存在于集合内，则放入
                set.insert(str[rk + 1]);
                rk++;
            }
            ans = max(ans, rk + 1 - i);
        }
        return ans;
    }

    static int lenOfLongestSubstring2(string str) {
        int n = str.length();
        if (n <= 1) {
            return n;
        }

        unordered_set<char> set; // 记录窗口中是否包含某个字符
        int l = 0, r = 1; // 窗口左右边界[l, r),左闭右开
        set.insert(str[0]);

        int ans = 1;
        while (l < n && r < n) {
            while (set.count(str[r]) <= 0 && r < n) { // 右移右边界找到第一个出现重复元素的字符
                set.insert(str[r]);
                r++;
            }
            // cout << "r: " << r << endl;
            ans = max(ans, r - l); // 记录当前窗口的长度
            while (l < n && set.count(str[r]) > 0) { // 右移左边界，一直到窗口中不存在和当前右边界重复的元素
                set.erase(str[l]);
                l++;
            }
            // cout << "l: " << l << endl;
        }
        return ans;
    }
};

int main() {
    cout << Solution::lenOfLongestSubstring2("abcabcbb");
}