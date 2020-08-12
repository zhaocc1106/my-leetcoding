/**
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 判断坐标是否合法，x为横坐标，y为纵坐标，左上角为坐标原点
    bool coordLegal(int x, int y, int m, int n, int k, vector<vector<bool>> &visit) {
        // 坐标是否超出范围
        if (x < 0 || x > n -1) {
            return false;
        }
        if (y < 0 || y > m - 1) {
            return false;
        }

        // 坐标是否已经访问过
        if (visit[y][x]) {
            return false;
        }

        // 坐标是否满足位和≤k
        int xSum = 0;
        while (x > 0) {
            xSum += x % 10;
            x /= 10;
        }
        int ySum = 0;
        while (y > 0) {
            ySum += y % 10;
            y /= 10;
        }
        return (xSum + ySum) <= k;
    }

    // 回溯法寻找当前坐标为(y, x)时，能到达的最多格子的个数
    int backtrace(int x, int y, int m, int n, int k, vector<vector<bool>> &visit) {
        if (!coordLegal(x, y, m, n, k, visit)) { // 如果当前坐标不合法
            return 0;
        }
        cout << y << ", " << x << endl;
        visit[y][x] = true;
        int ans = 1
                + backtrace(x - 1, y, m, n, k, visit) // 左移
                + backtrace(x + 1, y, m, n, k, visit) // 右移
                + backtrace(x, y + 1, m, n, k, visit) // 下移
                + backtrace(x, y - 1, m, n, k, visit) // 上移
                ;
        return ans;
    }

    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visit(m, vector<bool>(n, false)); // 记录坐标是否访问过
        return backtrace(0, 0, m, n, k, visit);
    }
};

int main() {
    cout << Solution().movingCount(3, 1, 0);
}