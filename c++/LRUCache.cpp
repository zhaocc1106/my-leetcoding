/**
 * LRU缓存
 *
 * 设计和构建一个“最近最少使用”缓存，该缓存会删除最近最少使用的项目。缓存应该从键映射到值(允许你插入和检索特定键对应的值)，并在初始化时指
 * 定最大容量。当缓存被填满时，它应该删除最近最少使用的项目。
 *
 * https://leetcode-cn.com/problems/lru-cache-lcci/
 */

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    int cap;
    list<pair<int, int>> cache; //双向列表用于存储key-value值
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap; // hash map用于保存key以及所在双向列表中的位置

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (cacheMap.count(key) <= 0) {
            return -1;
        }
        auto it = cacheMap[key];
        int val = it->second;
        cache.erase(it);
        cache.push_front(make_pair(key, val));
        cacheMap[key] = cache.begin();
        return val;
    }

    void put(int key, int value) {
        if (cacheMap.count(key) <= 0) { // 当前cache中不存在当前key-value
            cache.push_front(make_pair(key, value)); // 放入双向链表
        } else { // 当前cache中存在当前的key-value
            auto it = cacheMap[key];
            cache.erase(it);
            cache.push_front(make_pair(key, value));
        }
        cacheMap[key] = cache.begin();

        if (cache.size() > cap) { // 双向链表已经超过cache容量，删除尾部，即删除最近最少使用的元素
            int backKey = cache.back().first;
            cache.pop_back();
            cacheMap.erase(backKey);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */