/**
 * 编辑距离
 *
 * 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
 *
 * 你可以对一个单词进行如下三种操作：
 *
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 *
 * https://leetcode-cn.com/problems/edit-distance/
 */

#include <iostream>
#include <memory.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        int dp[m + 1][n + 1]; // dp[i][j]表示字符串1前i个和字符串2前j个转换时最少需要多少步
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= m; i++) {
            dp[i][0] = i; // 当字符串2为空时，则只能通过插入一个字符的方式来转换，添加字符的个数为字符串1的长度
        }

        for (int j = 1; j <= n; j++) {
            dp[0][j] = j; // 当字符串1为空，则只能通过插入一个字符的方式来转换，添加字符的个数为字符串2的长度
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // 当当前字符相同，则当前字符为截至的转换次数等于上一个
                } else {
                    dp[i][j] = min(
                            min(
                                    dp[i - 1][j] + 1, // 字符串1减少1个字符，或字符串2增加一个字符
                                    dp[i][j - 1] + 1), // 字符串1增加1个字符，或字符串2减少一个字符
                            dp[i - 1][j - 1] + 1); // 字符串1或2转换一个字符
                }
            }
        }
        return dp[m][n];
    }
};

int main() {

}