/**
 * 包含min函数的栈
 *
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
 *
 * https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/
 */

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> s1; // 存储所有数据
    stack<int> s2; // 只存储和最小数据相关的数据
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if (s2.empty()) {
            s2.push(x);
        } else if (s2.top() >= x) {
            s2.push(x);
        }

        s1.push(x);
    }

    void pop() {
        int val = s1.top();
        if (val == s2.top()) {
            s2.pop();
        }

        s1.pop();
    }

    int top() {
        if (s1.empty()) {
            return -1;
        }
        return s1.top();
    }

    int min() {
        if (s2.empty()) {
            return -1;
        }
        return s2.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.min() << endl; // 返回 -3.
    minStack.pop();
    cout << minStack.top() << endl; // 返回 0.
    cout << minStack.min() << endl; // 返回 -2.
}
