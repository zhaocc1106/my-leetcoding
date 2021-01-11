/**
* 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
*
* https://leetcode-cn.com/problems/group-anagrams/
*/

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:

    /* 超长case会超时 */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<unordered_map<char, int>> ans_maps; // answer对应的“字符个数map”的列表

        for (auto& str : strs) {
            unordered_map<char, int> c2count; // 记录字符串中“字符的个数map”
            for (char& c : str) {
                c2count[c]++;
            }

            int j = 0;
            for (; j < ans_maps.size(); j++) {
                auto& c2count1 = ans_maps[j]; // 当前answer中已有的“字符个数map”组

                if (c2count1.size() != c2count.size()) {
                    continue;
                }

                int check_count = 0;
                for (auto& item : c2count) {
                    if (c2count1.count(item.first) == 0
                        || c2count1[item.first] != item.second) { // 这里注意unordered_map只要调用过map[key]，就会新增一个key-value，包括判断语句
                        break;
                    }
                    check_count++;
                }

                if (check_count == c2count1.size()) { // 异位词，放到一组里
                    ans[j].emplace_back(str);
                    break;
                }
            }

            if (j >= ans.size()) { // 没找到异位词，添加新的组
                ans.emplace_back(vector<string>(1, str));
                ans_maps.emplace_back(c2count);
            }
        }

        return ans;
    }

    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string,vector<string>>mp;
        for(const auto& str:strs){
            auto key=str;
            sort(key.begin(),key.end());//key是排好序的一个单词
            mp[key].push_back(str);//value是排好序的单词对应的strs多个未排序的str集合
        }
        for(const auto&m:mp){
            res.push_back(m.second);//把value集合放进res
        }
        return res;
    }
};