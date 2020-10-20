/**
 * 最长有效括号
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/
 */

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() < 2) {
            return 0;
        }

        stack<pair<char, int>> st; // pair的first代表当前入栈的字符，second代表”紧邻“当前字符”后面“匹配括号成功的长度
        st.push(make_pair(')', 0)); // 增加一个伪节点，为了保存如果整个字符串都匹配成功时的总长度
        st.push(make_pair(s[0], 0)); // 字符串第一个节点入栈

        for (int i = 1; i < s.length(); i++) {
            if (st.top().first == '(' && s[i] == ')') { // 如果当前栈顶和字符串中当前字符配对成功，则要消掉这两个字符，并且将当前配对成功长度累加到栈的下面一个元素中
                int tmp = st.top().second;
                st.pop();
                st.top().second += 2 + tmp;
            } else { // 如果当前栈顶和字符串中当前字符配对失败，则将当前字符入栈
                st.push(make_pair(s[i], 0));
            }
        }

        // 所有在栈中遗留的元素的second记录了该元素后面配对成功的括号的长度，遍历一下栈取出最大长度即可
        int ans = 0;
        while (!st.empty()) {
            ans = max(ans, st.top().second);
            st.pop();
        }

        return ans;
    }
};

int main() {
    std::cout << Solution().longestValidParentheses("())((()()())") << std::endl;
}