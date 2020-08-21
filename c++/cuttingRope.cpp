/**
 * 剪绳子
 *
 * 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问
 * k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
 *
 * https://leetcode-cn.com/problems/jian-sheng-zi-lcof/
 */

#include <iostream>
#include <memory.h>

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        int dp[n + 1]; // dp[i]代表绳子长度为i时最大乘积值
        memset(dp, 0, sizeof(dp));
        dp[1] = 1; // 绳子长度为1，无法再分割

        for (int i = 1; i <= n; i++) { // 遍历所有的长度
            for (int j = 1; j < i; j++) { // j表示长度分割成j和i-j两段
                dp[i] = max(
                        dp[i],
                        max(dp[j], j) * max(dp[i - j], i - j) // 裁剪，有四种可能(根据j和i-j是否继续裁)，取较大值
                        );
            }
        }

        return dp[n];
    }

    int cuttingRope2(int n) {
        /* 数学公式推导，所有长度均分成n/e长度时乘积最大，由于裁剪都是整数，所以把e当成3*/

        if (n <= 3) {
            return n - 1;
        }

        if (n == 4) {
            return 4;
        }

        int ans = 1;
        while (n > 4) {
            ans = ans * 3;
            n -= 3;
            cout << n << endl;
        }
        if (n > 0) {
            ans = ans * n;
        }
        return ans;
    }
};

int main() {
    cout << Solution().cuttingRope2(10);
}