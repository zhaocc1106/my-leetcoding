/**
 * 根据身高重建队列
 *
 * 假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。
 * 编写一个算法来重建这个队列。
 *
 * https://leetcode-cn.com/problems/queue-reconstruction-by-height/
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <list>

using namespace std;

class Solution {
private:
    class myLess1 {
    public:
        bool operator()(const pair<int, int> &l, const pair<int, int> &r) const {
            return l.second > r.second;
        }
    };

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        // 相等身高放到一个group里，group使用优先级队列存放，顺序按照k顺序存放，小顶堆
        using group_type = priority_queue<pair<int, int>, vector<pair<int, int>>, myLess1>;

        // 使用逆序的map保存所有groups，key为身高
        map<int, group_type, greater<>> groups;
        for (auto peo : people) {
            if (groups.find(peo[0]) == groups.end()) { // map里未找到当前身高组，新建一个组，并添加一个人
                group_type group;
                group.push(make_pair(peo[0], peo[1]));
                groups.insert(make_pair(peo[0], group));
            } else { // map存在当前身高组，在身高组里再添加一个人，并且按照k顺序排序
                groups[peo[0]].push(make_pair(peo[0], peo[1]));
            }
        }

        list<vector<int>> resList; // 双向链表存放结果，便于插入
        for (auto group: groups) {
            while (!group.second.empty()) {
                auto peo = group.second.top();
                group.second.pop();
                vector<int> vec = {peo.first, peo.second};
                auto iter = resList.begin();
                advance(iter, peo.second);
                resList.insert(iter, vec);
                // for (auto item : resList) {
                //     cout << item[0] << "," << item[1] << endl;
                // }
                // cout << endl;
            }
        }

        vector<vector<int>> ans(resList.begin(), resList.end());
        return ans;
    }
};

int main() {
    vector<vector<int>> people;
    people.push_back({7, 0});
    people.push_back({4, 4});
    people.push_back({7, 1});
    people.push_back({5, 0});
    people.push_back({6, 1});
    people.push_back({5, 2});
    vector<vector<int>> ans = Solution().reconstructQueue(people);
    for (auto item : ans) {
        cout << item[0] << "," << item[1] << endl;
    }
}