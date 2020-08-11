/**
 * 字符串的排列
 *
 * 输入一个字符串，打印出该字符串中字符的所有排列。你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
 *
 * https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> permutation(string s) {
        if (s.length() == 0) {
            return {};
        }
        if (s.length() == 1) {
            return {s};
        }

        vector<string> ans;
        unordered_set<char> cutLeaf;
        for (int i = 0; i < s.length(); i++) {
            // 同一层相同字符只能出现一次，减枝
            if (cutLeaf.count(s[i]) > 0) {
                continue;
            }
            cutLeaf.insert(s[i]);

            string tmp = s;
            tmp.erase(i, 1); // 删除当前字符
            vector<string> subPer = permutation(tmp); // 获取子串的所有排列
            for (auto per : subPer) {
                // 当前层的排列等于当前字符加上子串的排列
                ans.push_back(s.substr(i, 1) + per);
            }
        }

        return ans;
    }
};

class Solution2 {
public:
    vector<string> ans;

    void backtrace(string &str, string &per, bool *visit) {
        if (str.length() == per.length()) { // 已经到达排列的长度，直接加入到结果中并返回
            ans.push_back(per);
            return;
        }

        unordered_set<char> cutLeaf; // 用于减枝
        for (int i = 0; i < str.length(); i++) {
            // 跳过已经访问过的元素
            if (visit[i]) {
                continue;
            }
            visit[i] = true;

            // 减枝，相同元素在同一位置不能重复出现
            if (cutLeaf.count(str[i]) > 0) {
                visit[i] = false;
                continue;
            }
            cutLeaf.insert(str[i]);

            per.push_back(str[i]);
            backtrace(str, per, visit);
            per.pop_back();
            visit[i] = false;
        }
    }

    vector<string> permutation(string s) {
        bool visit[s.length()]; // 保存当前位置的字符是否访问过
        memset(visit, 0, sizeof(visit));
        unordered_set<char> cutLeaf; // 用于减枝

        for (int i = 0; i < s.length(); i++) {
            visit[i] = true;

            // 减枝，相同元素在同一位置不能重复出现
            if (cutLeaf.count(s[i]) > 0) {
                visit[i] = false;
                continue;
            }
            cutLeaf.insert(s[i]);

            string per(1, s[i]);
            backtrace(s, per, visit); // 回溯寻找所有的排列
            visit[i] = false;
        }

        return ans;
    }
};

class Solution3 {
public:
    vector<string> ans;

    void backtrace(string &str, string &per, bool *visit) {
        if (str.length() == per.length()) { // 已经到达排列的长度，直接加入到结果中并返回
            ans.push_back(per);
            return;
        }

        for (int i = 0; i < str.length(); i++) {
            // 跳过已经访问过的元素
            if (visit[i]) {
                continue;
            }

            // 减枝，同一位置相同元素不能重复出现
            if (i > 0 && !visit[i - 1] && str[i - 1] == str[i]) {
                continue;
            }

            visit[i] = true;

            per.push_back(str[i]);
            backtrace(str, per, visit);
            per.pop_back();
            visit[i] = false;
        }
    }

    vector<string> permutation(string s) {
        sort(s.begin(), s.end()); // 先对字符串进行排序
        bool visit[s.length()]; // 保存当前位置的字符是否访问过
        memset(visit, 0, sizeof(visit));

        for (int i = 0; i < s.length(); i++) {
            // 减枝，同一位置相同元素不能重复出现
            if (i > 0 && !visit[i - 1] && s[i - 1] == s[i]) {
                continue;
            }

            visit[i] = true;
            string per(1, s[i]);
            backtrace(s, per, visit); // 回溯寻找所有的排列
            visit[i] = false;
        }

        return ans;
    }
};

int main() {
    string str = "aab";
    Solution2 solution2;
    solution2.permutation(str);
    for_each(solution2.ans.begin(), solution2.ans.end(), [](string str) { cout << str << endl; });
}