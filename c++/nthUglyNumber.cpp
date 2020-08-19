/**
 * 丑数
 *
 * 我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
 *
 * https://leetcode-cn.com/problems/chou-shu-lcof/
 */

#include <vector>
#include <memory.h>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int a = 0, b = 0, c = 0; // a,b,c分别代表当前2，3，5还没有乘过的丑数的位置
        int dp[n];
        memset(dp, 0, sizeof(dp));

        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            int n2 = dp[a] * 2;
            int n3 = dp[b] * 3;
            int n5 = dp[c] * 5;
            dp[i] = min(min(n2, n3), n5);

            if (dp[i] == n2) {
                a++;
            }
            if (dp[i] == n3) {
                b++;
            }
            if (dp[i] == n5) {
                c++;
            }
        }
        return dp[n - 1];
    }
};