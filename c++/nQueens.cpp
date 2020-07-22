/**
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<vector<string>> ans;

    static bool ifValid(vector<string> &row, int newQx, int newQy) {
        int n = row[0].size();
        // 相同列不能出现Q
        for (int i = newQx - 1; i >= 0; i--) {
            if (row[i][newQy] == 'Q') {
                return false;
            }
        }

        // 左上角不能出现Q
        for (int i = newQx - 1, j = newQy - 1; i >= 0 && j >= 0; i--, j--) {
            if (row[i][j] == 'Q') {
                return false;
            }
        }

        // 右上角不能出现Q
        for (int i = newQx - 1, j = newQy + 1; i >= 0 && j < n; i--, j++) {
            if (row[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    static void backtrace(vector<string> &row) {
        int n = row[0].size();
        if (row.size() == n) {
            ans.push_back(row);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!ifValid(row, row.size(), i)) { // 查看当且坐标是否合理
                continue;
            }
            row.push_back(string(n, '*')); // 将该行增加到rows里
            row[row.size() - 1][i] = 'Q'; // 当前坐标设置为Q
            backtrace(row); // 回溯获取后续行
            row.pop_back(); // 删除当前行
        }
    }

    static vector<vector<string>> solveNQueens(int n) {
        for (int i = 0; i < n; i++) {
            vector<string> board(1, string(n, '*')); // 初始化首行全部为*
            board[0][i] = 'Q'; // 设置当前i列为Q
            backtrace(board);
        }
        return ans;
    }

    static void showQueens() {
        for (auto board : ans) {
            cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
            for (auto row : board) {
                for (char c : row) {
                    cout << c << "  ";
                }
                cout << endl;
            }
            cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl << endl << endl;
        }
    }
};

vector<vector<string>> Solution::ans;

int main() {
    Solution::solveNQueens(8);
    Solution::showQueens();
}
