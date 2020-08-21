/**
 * 栈的压入、弹出序列
 *
 * 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如，序列
 * {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。
 *
 * https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        stack<int> s;

        int i = 0; // pushed元素标签
        int j = 0; // popped元素标签
        for (; i < pushed.size(); i++) {
            s.push(pushed[i]);
            while (!s.empty() && s.top() == popped[j]) { // 如果当前栈顶元素等于当前popped序列的元素，则弹出栈顶
                int item = s.top();
                s.pop();
                j++;
            }
        }

        return s.empty();
    }
};
