/**
 * 判断子序列
 *
 * 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
 *
 * 你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。
 *
 * 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子
 * 序列，而"aec"不是）。
 *
 * https://leetcode-cn.com/problems/is-subsequence/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // 双指针解法，时间复杂度为O(n)，n为t的长度
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0; // 双指针解法
        for (; i < t.length(); i++) {
            if (t[i] == s[j]) {
                j++; // 找到相同的字符，j指针加一
            }
            if (j == s.length()) { // 所有字符已经找到
                break;
            }
        }
        return j == s.length();
    }

    // 二分法解法，时间复杂度为O(mlog(n))，m为s长度，n为t长度，当m远小于n时，此时O(mlog(n)) < O(n)
    bool isSubsequence1(string s, string t) {
        vector<vector<int>> char2ind(256); // 存储256个字符对应在t字符串中的ind
        for (int i = 0; i < t.length(); i++) {
            char2ind[t[i]].push_back(i);
        }

        int minInd = -1; // s中当前字符在t中的位置需要大于哪个标签
        for (int j = 0; j < s.length(); j++) {
            cout << "minInd: " << minInd << endl;
            char cur = s[j];
            vector<int> arr = char2ind[cur];
            int min = 0;
            int max = arr.size() - 1;
            if (max < 0) { // t中没有s当前字符
                return false;
            }

            for (int ind : arr) {
                cout << ind << ", ";
            }
            cout << endl;

            // t中有s当前字符，寻找比s上一个字符大的标签
            while (min < max) { // 终止条件为min=max
                int mid = (max - min) / 2 + min;
                cout << "min: " << min << ", mid: " << mid  << ", max: " << max << endl;
                if (arr[mid] <= minInd) {
                    min = mid + 1;
                } else if (arr[mid] > minInd) {
                    max = mid - 1;
                }
            }
            if (arr[min] < minInd) { // s当前字符在t中的标签都比s上一个字符在t中的标签小
                return false;
            } else if (arr[min] == minInd) { // s当前字符在t中的标签和s上一个字符在t中的标签相等，则代表s出现了重复字符，标签应该加1
                if (min == arr.size() - 1) {
                    return false;
                } else {
                    min++;
                }
            }
            minInd = arr[min]; // 找到了当前s当前字符在t中的位置，下一个字符在t中的位置需要大于当前标签
        }
        return true;
    }
};

int main() {
    cout << Solution().isSubsequence1("aaaaaa", "bbaaaa");
}