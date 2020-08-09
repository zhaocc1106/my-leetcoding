/**
 * 鸡蛋掉落
 * 你将获得 K 个鸡蛋，并可以使用一栋从 1 到 N  共有 N 层楼的建筑。
 * 每个蛋的功能都是一样的，如果一个蛋碎了，你就不能再把它掉下去。
 * 你知道存在楼层 F ，满足 0 <= F <= N 任何从高于 F 的楼层落下的鸡蛋都会碎，从 F 楼层或比它低的楼层落下的鸡蛋都不会破。
 * 每次移动，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层 X 扔下（满足 1 <= X <= N）。
 * 你的目标是确切地知道 F 的值是多少。
 * 无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少？
 * https://leetcode-cn.com/problems/super-egg-drop/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int eggDrop(int K, int N, int **dp) {
        if (K == 1) return N; // 如果只有一个鸡蛋，则只能线性搜索，从最底层开始一层一层尝试，最多尝试次数为N
        if (N == 0) return 0; // 如果没有楼层，则最多就是0次

        // 避免重复计算
        if (dp[K - 1][N - 1] != 0) {
            return dp[K - 1][N - 1];
        }

        int res = INT32_MAX;
        int low = 1;
        int high = N;
        while (low <= high) {
            int mid = (low + high) / 2;
            int broken = eggDrop(K - 1, mid - 1, dp); // 如果摔碎了，则去下层楼试一下
            int notBroken = eggDrop(K, N - mid, dp); // 如果没摔碎，则去上一层楼继续摔
            if (broken > notBroken) {
                high = mid - 1; // 如果摔碎的更大一些，则低层探索
                res = min(res, broken + 1);
            } else {
                low = mid + 1; // 如果没摔碎的更大一些，则在高层探索
                res = min(res, notBroken + 1);
            }
        }

        dp[K - 1][N - 1] = res;
        cout << "K: " << K << ", N: " << N << ", res: " << res << endl;

        return res;
    }

    int eggDrop2(int K, int N, int **dp) {
        if (K == 1) return N; // 如果只有一个鸡蛋，则只能线性搜索，从最底层开始一层一层尝试，最多尝试次数为N
        if (N == 0) return 0; // 如果没有楼层，则最多就是0次

        // 避免重复计算
        if (dp[K - 1][N - 1] != 0) {
            return dp[K - 1][N - 1];
        }

        int res = INT32_MAX;
        for (int i = 1; i <= N; i++) {
            res = min(
                    res,
                    max(
                            eggDrop2(K, N - i, dp), // 没摔碎
                            eggDrop2(K - 1, i - 1, dp) // 摔碎了
                    ) + 1
            );
        }

        dp[K - 1][N - 1] = res;
        cout << "K: " << K << ", N: " << N << ", res: " << res << endl;

        return res;
    }

    int superEggDrop(int K, int N) {
        int **dp = new int *[K];
        dp[0] = new int[K * N]{0}; // 申请连续内存
        for (int i = 1; i < K; i++) {
            dp[i] = dp[i - 1] + N;
        }
        // vector<vector<int>> dp(K, vector<int>(N, -1));
        int res = eggDrop2(K, N, dp);
        delete[]dp[0];
        delete[]dp;
        return res;
    }
};

int main() {
    Solution solution;
    cout << solution.superEggDrop(10, 100) << endl;
}
