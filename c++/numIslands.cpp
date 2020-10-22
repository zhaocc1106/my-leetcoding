/**
 * 岛屿数量
 *
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 *
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 *
 * 此外，你可以假设该网格的四条边均被水包围。
 *
 * https://leetcode-cn.com/problems/number-of-islands/
 */

#include <vector>
#include <iostream>
#include "unionFind.h"

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }

        int n = grid[0].size();
        if (n == 0) {
            return 0;
        }

        UF uf(m * n); // 初始有m * n个联通分量
        int zero_count = 0; // 记录0的个数

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    if (i > 0 && grid[i - 1][j] == '1') { // 上面那格也是1，则联通他俩
                        uf.unionTree(i * n + j, (i - 1) * n + j);
                    }
                    if (j > 0 && grid[i][j - 1] == '1') { // 左面那格也是1，则联通他俩
                        uf.unionTree(i * n + j, i * n + j - 1);
                    }
                } else {
                    zero_count++;
                }
            }
        }

        cout << "union_count: " << uf.unionCount() << endl;
        return uf.unionCount() - zero_count; // 0不是连通分量，减去它
    }
};

int main() {
    vector<vector<char>> grid{{'1', '1', '1', '1', '0'},
                              {'1', '1', '0', '1', '0'},
                              {'1', '1', '0', '0', '0'},
                              {'0', '0', '0', '0', '0'}};
    vector<vector<char>> grid2{{'1', '1', '0', '0', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'0', '0', '1', '0', '0'},
                               {'0', '0', '0', '1', '1'}};

    cout << Solution().numIslands(grid) << endl;
    cout << Solution().numIslands(grid2) << endl;
}