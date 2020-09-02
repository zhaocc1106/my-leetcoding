/**
 * 被围绕的区域
 *
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 *
 * https://leetcode-cn.com/problems/surrounded-regions/
 */
#include <iostream>
#include <vector>
#include "unionFind.h"

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.size() == 0) {
            return;
        }

        int m = board.size();
        int n = board[0].size();

        // 多出来一个节点代表dummy，即是无法被包围的‘O’组
        UF uf(m * n + 1);
        int dummy = m * n;

        // 将第一列和最后一列O均放到dummy组里，即和dummy联通
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                uf.unionTree(i * n, dummy);
            }
            if (board[i][n - 1] == 'O') {
                uf.unionTree(i * n + n - 1, dummy);
            }
        }

        // 将第一行和最后一行O和dummy联通
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                uf.unionTree(j, dummy);
            }
            if (board[m - 1][j] == 'O') {
                uf.unionTree((m - 1) * n + j, dummy);
            }
        }

        // 方向数组，代表上下左右四个方向
        int dir[4][2] = {{0, 1}, // 右移
                         {0, -1}, // 左移
                         {1, 0}, // 下移
                         {-1, 0}}; // 上移

        // 将中间的所有和四周相连的O进行联通
        for (int i = 1; i < m -1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (board[i][j] != 'O') { // 当前坐标不是O，跳过
                    continue;
                }

                for (auto & k : dir) {
                    int y = i + k[0]; // y轴方向移动
                    int x = j + k[1]; // x轴方向移动
                    if (board[y][x] == 'O') {
                        uf.unionTree(i * n + j, y * n + x); // 联通当前坐标和周围为O坐标
                    }
                }
            }
        }

        // 所有和dummy不连通的元素置为X
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (!uf.connected(i * n + j, dummy)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main() {
    vector<vector<char>> board(4, vector<char>(4, 'X'));
    board[1][1] = 'O';
    board[1][2] = 'O';
    board[2][2] = 'O';
    board[3][1] = 'O';
    Solution().solve(board);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << board[i][j] << ",  ";
        }
        cout << endl;
    }
}