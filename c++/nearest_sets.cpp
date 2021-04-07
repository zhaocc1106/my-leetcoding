#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

using namespace std;

class Solution {
public:
    /**
    * 输入是一个整型数组，以及一个目标值（整型），求出数组中哪几个元素的和最接近目标值，返回数组元素的下标（下标最小是0）列表，如果有多组的元素和
    * 相同就输出多行（每行是一组元素的下标列表）。
    * @param arr: 数组
    * @param target: 目标值
    * @return: 和最接近目标值的组合
    */
    static vector<vector<int>> get_nearest_arr(const vector<int>& arr, int target) {
        int len = arr.size();
        if (len == 0) {
            return {};
        }

        _perms.clear();
        _travel.clear();
        /* 生成所有下标的所有子集 */
        vector<int> idx_arr;
        for (int i = 0; i < len; i++) {
            idx_arr.emplace_back(i);
        }
        for (int i = 1; i <= len; i++) { // 生成所有不同长度的子集
            backtrace(idx_arr, 0, i);
        }

        vector<vector<int>> ans;
        uint32_t cur_nearest_sum_diff = UINT32_MAX; // 记录当前组合中和与目标值相减后相差最小的值
        for (auto& perm : _perms) {
            int sum = 0;
            for (auto& num : perm) {
                sum += arr[num];
            }
            uint32_t diff = abs(target - sum);
            if (diff < cur_nearest_sum_diff) { // 寻找到和更接近目标值的组合，清除之前的结果
                cur_nearest_sum_diff = diff;
                ans.clear();
                ans.emplace_back(perm);
            } else if (diff == cur_nearest_sum_diff) { // 寻找到同当前最优组合相同的组合，追加到结果中
                ans.emplace_back(perm);
            }
        }

        return ans;
    }

    /* 仿函数类，用于排序vector<int> */
    class MyLess {
    public:

        bool operator()(const vector<int>& arr1, const vector<int>& arr2) {
            if (arr1.size() < arr2.size()) {
                return true;
            } else if (arr1.size() > arr2.size()) {
                return false;
            } else {
                for (int i = 0; i < arr1.size(); i++) {
                    if (arr1[i] != arr2[i]) {
                        return arr1[i] < arr2[i];
                    }
                }
                return true;
            }
        }
    };

    /**
    * 判断两个二维数组是否相等，用于单元测试检查
    * @param arrs1: 数组1
    * @param arrs2: 数组2
    * @return
    */
    static bool is_same(const vector<vector<int>>& arrs1, const vector<vector<int>>& arrs2) {
        if (arrs1.size() != arrs2.size()) {
            return false;
        }

        /* 排序两个二维数组 */
        priority_queue<vector<int>, vector<vector<int>>, MyLess> que1;
        for (auto& arr : arrs1) {
            que1.push(arr);
        }
        priority_queue<vector<int>, vector<vector<int>>, MyLess> que2;
        for (auto& arr : arrs2) {
            que2.push(arr);
        }

        /* 判断两个二维数组是否相等 */
        while(!que1.empty()) {
            auto arr1 = que1.top();
            que1.pop();
            auto arr2 = que2.top();
            que2.pop();
            for (int i = 0; i < arr1.size(); i++) {
                if (arr1[i] != arr2[i]) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    /**
   * 回溯法求解所有子集
   * @param nums: 数组
   * @param begin: 数组起始位置
   * @param left_len: 当前组合剩余填充的长度
   */
    static void backtrace(const vector<int>& nums, int begin, int left_len) {
        if (left_len == 0) {
            _perms.emplace_back(_travel);
            return;
        }

        for (int i = begin; i < nums.size() - left_len + 1; i++) {
            _travel.emplace_back(nums[i]);
            backtrace(nums, i + 1, left_len - 1);
            _travel.pop_back();
        }
    }

    static vector<vector<int>> _perms; // 存储下标所有的子集
    static vector<int> _travel; // 当前存储的子集
};

vector<vector<int>> Solution::_perms;
vector<int> Solution::_travel;

int main() {
    // 边界条件检测
    auto ans = Solution::get_nearest_arr({}, 4);
    assert(ans.empty());

    // 存在和相等于目标值单个最优解检测
    auto ans2 = Solution::get_nearest_arr({1, 2, 3}, 2);
    assert(Solution::is_same(ans2, {{1}}));

    // 存在和相等于目标值多个最优解检测
    auto ans3 = Solution::get_nearest_arr({1, 2, 3}, 3);
    assert(Solution::is_same(ans3, {{2}, {0, 1}}));

    // 不存在和相等于目标值单个值检测
    auto ans4 = Solution::get_nearest_arr({1, 2, 3}, 0);
    assert(Solution::is_same(ans4, {{0}}));

    // 不存在和相等于目标值多个值检测
    auto ans5 = Solution::get_nearest_arr({2, 2, 2}, 5);
    assert(Solution::is_same(ans5, {{0,1}, {0, 2}, {1, 2}, {0, 1, 2}}));
    return 0;
}