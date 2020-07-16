/**
 * https://leetcode-cn.com/problems/implement-stack-using-queues/
 */

#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

class Stack {
private:
    queue<int> q1;
    int topVal;

public:
    Stack() {
    }

    void push(int i) {
        q1.push(i);
        topVal = i;
    }

    int pop() {
        assert(q1.size());
        queue<int> q2;
        int res;

        while (q1.size() > 0) {
            if (q1.size() == 1) {
                res = q1.front();
            } else {
                q2.push(q1.front());
            }
            q1.pop();
        }

        while (q2.size()) {
            if (q2.size() == 1) {
                topVal = q2.front();
            }
            q1.push(q2.front());
            q2.pop();
        }

        return res;
    }

    int top() {
        assert(q1.size() > 0);
        return topVal;
    }

    bool empty() {
        return q1.size() == 0;
    }
};