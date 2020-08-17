/**
 * II. 队列的最大值
 *
 *
 * 请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
 * 若队列为空，pop_front 和 max_value 需要返回 -1
 *
 * https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/
 */

#include <deque>
#include <queue>

using namespace std;

class MaxQueue {
private:
    deque<int> d; // 保存最大值的队列
    queue<int> q; // 真正保存数据的队列

public:
    MaxQueue() {

    }

    int max_value() {
        if (d.empty()) {
            return -1;
        }
        return d.front();
    }

    void push_back(int value) {
        while (!d.empty() && d.back() < value) { // 对于出队的值，因为这些值在q中不出队之前，最大值都不是他们，所以这些无关紧要
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }

    int pop_front() {
        if (q.empty()) {
            return -1;
        }

        int val = q.front();
        if (d.front() == val) {
            d.pop_front();
        }
        q.pop();
        return val;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */