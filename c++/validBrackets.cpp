/**
 * 有效的括号
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 有效字符串需满足：
 *
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 注意空字符串可被认为是有效字符串。
 *
 * https://leetcode-cn.com/problems/valid-parentheses/
 */

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    char leftOf(char right) {
        switch (right) {
            case ')':
                return '(';
            case ']':
                return '[';
            default:
                return '{';
        }
    }

    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == ')' || c == ']' || c == '}') {
                if (!st.empty() && st.top() == leftOf(c)) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};

int main() {
    cout << Solution().isValid("(({[][]}))");
}