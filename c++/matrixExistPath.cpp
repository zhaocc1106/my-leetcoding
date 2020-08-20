/**
 * 矩阵中的路径
 *
 * 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左
 * 、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”
 * 的路径（路径中的字母用加粗标出）。
 *
 * [["a","b","c","e"],
 * ["s","f","c","s"],
 * ["a","d","e","e"]]
 *
 * 但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
 *
 * https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param board: 存放矩阵
     * @param x: 当前x轴坐标
     * @param y: 当前y轴坐标
     * @param visit: 当前访问矩阵，某个坐标为true，代表该坐标已访问
     * @param word: 目标字符串
     * @param cur: 当前寻找字符在目标字符串中的坐标
     * @param reverse: 是否是逆序寻找目标字符串
     * @return 能够找对目标字符串
     */
    bool dfs(vector<vector<char>>& board, int x, int y, vector<vector<bool>>& visit, string &word, int cur, bool reverse) {
        if ((cur == word.length() - 1 && !reverse) || (cur == 0 && reverse)) { // 如果所有目标字符串字符已找到，直接返回true
            // cout << cur << ", 0" << endl;
            return true;
        }

        int m = board.size();
        int n = board[0].size();

        if (reverse) {
            cur--;
        } else {
            cur++;
        }

        char curChar = word[cur];
        if (x + 1 < n && !visit[y][x + 1] && board[y][x + 1] == curChar) { // 右移找到下一个字符
            // cout << "2" << endl;
            visit[y][x + 1] = true;
            if (dfs(board, x + 1, y, visit, word, cur, reverse)) { // 右移寻找
                return true;
            }
            visit[y][x + 1] = false;
        }

        if (y + 1 < m && !visit[y + 1][x] && board[y + 1][x] == curChar) { // 下移找到下一个字符
            // cout << "4" << endl;
            visit[y + 1][x] = true;
            if (dfs(board, x, y + 1, visit, word, cur, reverse)) { // 下移寻找
                return true;
            }
            visit[y + 1][x] = false;
        }

        if (x - 1 >= 0 && !visit[y][x - 1] && board[y][x - 1] == curChar) { // 左移找到下一个字符
            // cout << "1" << endl;
            visit[y][x - 1] = true;
            if (dfs(board, x - 1, y, visit, word, cur, reverse)) { // 左移寻找
                return true;
            }
            visit[y][x - 1] = false;
        }

        if (y - 1 >= 0 && !visit[y - 1][x] && board[y - 1][x] == curChar) { // 上移找到下一个字符
            // cout << "3" << endl;
            visit[y - 1][x] = true;
            if (dfs(board, x, y - 1, visit, word, cur, reverse)) { // 上移寻找
                return true;
            }
            visit[y - 1][x] = false;
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (word.length() == 0) {
            return false;
        }

        int m = board.size();
        int n = board[0].size();

        char begin = word[0]; // 首字符
        char end = word[word.length() - 1]; // 尾字符
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char cur = board[i][j];
                if (cur == begin) { // 如果找到首字符，则开始dfs遍历寻找
                    vector<vector<bool>> visit(m, vector<bool>(n, false));
                    visit[i][j] = true;
                    if (dfs(board, j, i, visit, word, 0, false)) {
                        return true;
                    }
                    visit[i][j] = false;
                }
                // if (cur == end) { // 如果找到尾字符，则开始dfs遍历寻找
                //     vector<vector<bool>> visit(m, vector<bool>(n, false));
                //     visit[i][j] = true;
                //     if (dfs(board, j, i, visit, word, word.length() - 1, true)) {
                //         return true;
                //     }
                //     visit[i][j] = false;
                // }
            }
        }

        return false;
    }
};
