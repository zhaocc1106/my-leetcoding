/**
 * 前 K 个高频元素
 *
 * 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
 *
 * https://leetcode-cn.com/problems/top-k-frequent-elements/
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    class myLess {
    public:
        bool operator()(const pair<int, int> l, const pair<int, int> r) {
            return l.second > r.second; // 倒序
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> freqMap;
        for (auto num : nums) {
            freqMap[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, myLess> heap; // 小顶堆
        for (auto freq : freqMap) {
            heap.push(freq);
            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(heap.top().first);
            heap.pop();
        }
        return ans;
    }
};
