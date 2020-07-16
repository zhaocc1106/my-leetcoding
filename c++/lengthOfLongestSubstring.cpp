/**
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
};