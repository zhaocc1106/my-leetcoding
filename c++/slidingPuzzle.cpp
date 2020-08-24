/**
 * 滑动谜题
 *
 * 在一个 2 x 3 的板上（board）有 5 块砖瓦，用数字 1~5 来表示, 以及一块空缺用 0 来表示.
 *
 * 一次移动定义为选择 0 与一个相邻的数字（上下左右）进行交换.
 *
 * 最终当板 board 的结果是 [[1,2,3],[4,5,0]] 谜板被解开。
 *
 * 给出一个谜板的初始状态，返回最少可以通过多少次移动解开谜板，如果不能解开谜板，则返回 -1 。
 *
 * https://leetcode-cn.com/problems/sliding-puzzle/
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <deque>

using namespace std;

class Solution {
public:
    //寻找0的位置
    int findZero(string board) {
        for (int i = 0; i < board.length(); i++) {
            if (board[i] == '0') {
                return i;
            }
        }
        return -1;
    }

    // 上移
    bool up(string &board) {
        int zeroInd = findZero(board);
        if (zeroInd - 3 >= 0) {
            char tmp = board[zeroInd];
            board[zeroInd] = board[zeroInd - 3];
            board[zeroInd - 3] = tmp;
            return true;
        }
        return false;
    }

    // 下移
    bool down(string &board) {
        int zeroInd = findZero(board);
        if (zeroInd + 3 <= board.length() - 1) {
            char tmp = board[zeroInd];
            board[zeroInd] = board[zeroInd + 3];
            board[zeroInd + 3] = tmp;
            return true;
        }
        return false;
    }

    // 左移
    bool left(string &board) {
        int zeroInd = findZero(board);
        int leftLimit = zeroInd / 3 * 3; // 左移的边界
        if (zeroInd - 1 >= leftLimit) {
            char tmp = board[zeroInd];
            board[zeroInd] = board[zeroInd - 1];
            board[zeroInd - 1] = tmp;
            return true;
        }
        return false;
    }

    // 右移
    bool right(string &board) {
        int zeroInd = findZero(board);
        int rightLimit = zeroInd / 3 * 3 + 2; // 右移的边界
        if (zeroInd + 1 <= rightLimit) {
            char tmp = board[zeroInd];
            board[zeroInd] = board[zeroInd + 1];
            board[zeroInd + 1] = tmp;
            return true;
        }
        return false;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        // 将board转成字符串
        ostringstream out;
        for (auto row : board) {
            for (auto val : row) {
                out << val;
            }
        }
        string boardStr = out.str();
        cout << "boardStr: " << boardStr << endl;

        string target = "123450"; // 目标字符串
        unordered_set<string> visitSet; // 用于保存所有已经访问过的字符串

        deque<string> boardQue; // 用于保存所有需要遍历的board
        boardQue.push_back(boardStr);
        visitSet.insert(boardStr);

        int step = 0;
        while (!boardQue.empty()) {
            int len = boardQue.size();
            for (int i = 0; i < len; i++) {
                string curBoard = boardQue.front();
                boardQue.pop_front();
                // cout << curBoard << ",";

                if (target == curBoard) {
                    return step;
                }

                // 上移
                string tmp = curBoard;
                if (up(tmp) && visitSet.count(tmp) <= 0) { // 如果当前没访问过
                    // cout << "(" + curBoard << ", " << tmp << ")";
                    visitSet.insert(tmp);
                    boardQue.push_back(tmp);
                }

                // 下移
                tmp = curBoard;
                if (down(tmp) && visitSet.count(tmp) <= 0) { // 如果当前没访问过
                    // cout << "(" + curBoard << ", " << tmp << ")";
                    visitSet.insert(tmp);
                    boardQue.push_back(tmp);
                }

                // 左移
                tmp = curBoard;
                if (left(tmp) && visitSet.count(tmp) <= 0) { // 如果当前没访问过
                    // cout << "(" + curBoard << ", " << tmp << ")";
                    visitSet.insert(tmp);
                    boardQue.push_back(tmp);
                }

                // 右移
                tmp = curBoard;
                if (right(tmp) && visitSet.count(tmp) <= 0) { // 如果当前没访问过
                    // cout << "(" + curBoard << ", " << tmp << ")";
                    visitSet.insert(tmp);
                    boardQue.push_back(tmp);
                }
            }
            cout << endl << endl;
            step++;
        }

        return -1;
    }
};

int main() {
    vector<vector<int>> board;
    board.push_back({3, 2, 4});
    board.push_back({1, 5, 0});
    cout << Solution().slidingPuzzle(board) << endl;
}