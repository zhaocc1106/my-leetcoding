/**
 * 回溯法解全排列问题
 * https://leetcode-cn.com/problems/permutations/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static vector<vector<int>> ans;

    static void backtrace(const vector<int> &arr, vector<int> &per) {
        if (per.size() == arr.size()) {
            ans.push_back(per);
            return;
        }
        for (auto item : arr) {
            // 跳过重复的元素
            if (count(per.begin(), per.end(), item) > 0) {
                continue;
            }

            per.push_back(item); // 把非重复值放入permutation中
            backtrace(arr, per); // 回溯法获取后续的数值
            per.pop_back(); // 当前值移除
        }
    }

    static vector<vector<int>> permute(const vector<int> &arr) {
        for (auto item : arr) {
            vector<int> per{item};
            backtrace(arr, per);
        }
        return ans;
    }
};

vector<vector<int>> Solution::ans;

int main() {
    Solution::permute({1, 2, 3});
    for (auto per : Solution::ans) {
        for (auto item : per) {
            cout << item << ", ";
        }
        cout << endl;
    }
}