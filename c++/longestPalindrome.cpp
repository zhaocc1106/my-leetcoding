/**
 * 最长回文
 * https://leetcode-cn.com/problems/longest-palindromic-substring
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string str) {
        int n = str.length();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        for (int l = 0; l < n; l++) {
            for (int i = 0; i + l < n; ++i) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = 1;
                } else if (l == 1) {
                    dp[i][j] = (str[i] == str[j]);
                } else {
                    dp[i][j] = (dp[i + 1][j - 1] == 1 && str[i] == str[j]);
                }
                if (dp[i][j] && l + 1 > ans.length()) {
                    ans = str.substr(i, l + 1);
                }
            }
        }
        return ans;
    }
};