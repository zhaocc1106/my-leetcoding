/**
 * 单词搜索
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 *
 * https://leetcode-cn.com/problems/word-search/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int m;
    int n;

    bool recur(vector<vector<char>>& board, string& word, int x, int y, int ind, vector<vector<bool>>& tracked) {
        if (ind == word.size()) { // 全部字符都已找到
            return true;
        }

        // 向右探索
        if (y < n - 1 // 没越界
            && !tracked[x][y + 1] // 没有在探索路径中
            && board[x][y + 1] == word[ind]) { // 当前位置的字符能对上
            tracked[x][y + 1] = true; // 记录当前位置已经在探索路径中
            if (recur(board, word, x, y + 1, ind + 1, tracked)) {
                return true;
            } else {
                tracked[x][y + 1] = false; // 当前位置从探索路径中移出
            }
        }

        // 向下探索
        if (x < m - 1 // 没越界
            && !tracked[x + 1][y] // 没有在探索路径中
            && board[x + 1][y] == word[ind]) { // 当前位置的字符能对上
            tracked[x + 1][y] = true;
            if (recur(board, word, x + 1, y, ind + 1, tracked)) {
                return true;
            } else {
                tracked[x + 1][y] = false;
            }
        }

        // 向左探索
        if (y > 0 // 没越界
            && !tracked[x][y - 1] // 没有在探索路径中
            && board[x][y - 1] == word[ind]) { // 当前位置的字符能对上
            tracked[x][y - 1] = true;
            if (recur(board, word, x, y - 1, ind + 1, tracked)) {
                return true;
            } else {
                tracked[x][y - 1] = false;
            }
        }

        // 向上探索
        if (x > 0 // 没越界
            && !tracked[x - 1][y] // 没有在探索路径中
            && board[x - 1][y] == word[ind]) { // 当前位置的字符能对上
            tracked[x - 1][y] = true;
            if (recur(board, word, x - 1, y, ind + 1, tracked)) {
                return true;
            } else {
                tracked[x - 1][y] = false;
            }
        }

        return false;
    }
public:

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        if (m == 0) {
            return false;
        }

        n = board[0].size();
        if (n == 0) {
            return false;
        }

        vector<vector<bool>> tracked(m, vector<bool>(n, false)); // 表示当前路径是否已经在探索的路径中
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) { // 首字符匹配成功
                    tracked[i][j] = true;
                    if (recur(board, word, i, j, 1, tracked)) {
                        return true;
                    }
                    tracked[i][j] = false;
                }
            }
        }

        return false;
    }
};