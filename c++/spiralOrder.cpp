/**
 * 顺时针打印矩阵
 *
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
 *
 * https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef enum {
    r, // 右移
    d, // 下移
    l, // 左移
    u // 上移
} direction;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int h = matrix.size(); // 矩阵高
        if (h == 0) {
            return {};
        }
        int w = matrix[0].size(); // 矩阵宽
        if (w == 0) {
            return {};
        }

        vector<int> ans;
        for (int i = 0; i < w; i++) { // 第一行先放进去
            cout << matrix[0][i] << ",";
            ans.push_back(matrix[0][i]);
        }

        direction dir = d; // 初始方向为下
        int x = w - 1; // 初始x坐标
        int y = 0; // 初始y坐标
        int size = w * h;
        w--; // 初始横向转移长度
        h--; // 初始纵向转移长度

        while ((w > 0 || h > 0) && ans.size() != size) {
            switch (dir) {
            case r:
                cout << "r,";
                for (int i = 0; i < w; i++) {
                    x++;
                    cout << matrix[y][x] << ",";
                    ans.push_back(matrix[y][x]); // 右移
                }
                dir = d; // 切换方向向下
                w--; // 下次水平方向移动次数减一
                break;
            case d:
                cout << "d,";
                for (int i = 0; i < h; i++) {
                    y++;
                    cout << matrix[y][x] << ",";
                    ans.push_back(matrix[y][x]); // 下移
                }
                dir = l;
                h--;
                break;
            case l:
                cout << "l,";
                for (int i = 0; i < w; i++) {
                    x--;
                    cout << matrix[y][x] << ",";
                    ans.push_back(matrix[y][x]); // 左移
                }
                dir = u;
                w--;
                break;
            case u:
                cout << "u,";
                for (int i = 0; i < h; i++) {
                    y--;
                    cout << matrix[y][x] << ",";
                    ans.push_back(matrix[y][x]); // 上移
                }
                dir = r;
                h--;
                break;
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> matrix(3, vector<int>(4, 0));
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = count;
            count++;
        }
    }
    for (auto row : matrix) {
        for (auto item : row) {
            cout << item << ", ";
        }
        cout << endl;
    }

    vector<int> ans = Solution().spiralOrder(matrix);
//    for (auto item : ans) {
//        cout << item << ", ";
//    }
}