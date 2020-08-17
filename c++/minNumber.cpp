/**
 * 把数组排成最小的数
 *
 * 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
 *
 * https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minNumber(vector<int>& nums) {
        auto compare = [](string str1, string str2){return str1 + str2 < str2 + str1;};

        vector<string> tmp;
        for (auto num : nums) {
            tmp.push_back(to_string(num));
        }
        sort(tmp.begin(), tmp.end(), compare);

        string ans;
        for (auto str : tmp) {
            ans += str;
        }
        return ans;
    }
};