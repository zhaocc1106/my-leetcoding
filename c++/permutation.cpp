/**
 * https://leetcode-cn.com/problems/permutations/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<vector<int>> permute(const vector<int> &arr) {
        if (arr.size() == 0) {
            return {};
        }
        vector<vector<int>> out;

        for (int i = 0; i < arr.size(); ++i) {
            vector<int> subArr = arr;
            subArr.erase(subArr.begin() + i); // 删除当前元素，获得子串
            vector<vector<int>> subPerm = permute(subArr); // 递归寻找所有子串的组合
            if (subPerm.size() == 0) {
                out.push_back(vector<int>{arr[i]}); // 如果子串组合为空，则只添加当前元素
            } else {
                for (int j = 0; j < subPerm.size(); ++j) {  // 如果子串组合不为空，则和当前元素结合成所有的组合
                    vector<int> curPerm{arr[i]};
                    curPerm.insert(curPerm.end(), subPerm[j].begin(), subPerm[j].end());
                    out.push_back(curPerm);
                }
            }
        }
        return out;
    }
};

int main() {
    vector<int> arr{1, 2, 3};
    vector<vector<int>> out = Solution::permute(arr);
    for (auto perm : out) {
        for (auto i : perm) {
            cout << i;
        }
        cout << endl;
    }
}
