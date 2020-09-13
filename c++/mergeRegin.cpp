/**
 * 合并区间
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 *
 * https://leetcode-cn.com/problems/merge-intervals/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    class MyLess {
    public:
        bool operator()(const vector<int> &l, const vector<int> &r) const {
            return l[0] < r[0];
        }
    };

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &l, const vector<int> &r) { return l[0] < r[0]; }); // 按照起始点进行排序
        vector<vector<int>> ans;
        int n = intervals.size();
        if (n == 1) {
            return intervals;
        }
        int l = intervals[0][0];
        int r = intervals[0][1];
        // cout << "l: " << l << ", r: " << r << endl;
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= l && intervals[i][0] <= r) { // 当前段落起始点在上一个间隔的中间
                r = max(r, intervals[i][1]); // 合并段落，并且右端点为两个段落较大的右端点
                continue;
            }
            ans.push_back({l, r});
            l = intervals[i][0];
            r = intervals[i][1];
        }
        ans.push_back({l, r}); // 最后一组放入
        return ans;
    }
};

int main() {
    vector<vector<int>> intervals;
    intervals.push_back({1, 4});
    intervals.push_back({0, 4});
    vector<vector<int>> ans = Solution().merge(intervals);
    for (auto interval : ans) {
        cout << interval[0] << ", " << interval[1] << endl;
    }
}
