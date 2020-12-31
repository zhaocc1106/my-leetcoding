/**
* 给定一个 n × n 的二维矩阵表示一个图像。将图像顺时针旋转 90 度。
* https://leetcode-cn.com/problems/rotate-image/submissions/
*/

#include <iostream>
#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int x = 0; // 纵坐标
        for (int round_len = matrix.size(); round_len >= 2; round_len -= 2) { // 从外圈到内圈
            // printf("round_len == %d\n", round_len);
            for (int j = 0; j < round_len - 1; j++) {
                int tmp = matrix[x][j + x];
                matrix[x][j + x] = matrix[round_len - j - 1 + x][x];
                // printf("(%d, %d) -> (%d, %d)\n", round_len - j - 1 + x, x, x, j + x);
                matrix[round_len - j - 1 + x][x] = matrix[round_len - 1 + x][round_len - j - 1 + x];
                // printf("(%d, %d) -> (%d, %d)\n", round_len - 1 + x, round_len - j - 1 + x, round_len - j - 1 + x, x);
                matrix[round_len - 1 + x][round_len - j - 1 + x] = matrix[j + x][round_len - 1 + x];
                // printf("(%d, %d) -> (%d, %d)\n", j + x, round_len - 1 + x, round_len - 1 + x, round_len - j - 1 + x);
                matrix[j + x][round_len - 1 + x] = tmp;
                // printf("(%d, %d) -> (%d, %d)\n", x, j + x, j + x, round_len - 1 + x);
            }
            x++;
        }
    }
};