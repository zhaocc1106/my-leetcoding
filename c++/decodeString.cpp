/**
 * 字符串解码
 *
 * 给定一个经过编码的字符串，返回它解码后的字符串。
 *
 * 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
 *
 * 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
 *
 * 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
 *
 * https://leetcode-cn.com/problems/decode-string/
 */

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    // 递归求解, begin代表当前层起始位置，end用于返回当前层结束位置
    string recu(string &s, int begin, int &end) {
        // cout << "recu begin: " << begin << endl;
        stringstream ans;
        int i = begin;
        while (s[i] != ']') {
            for (; s[i] != ']' && (s[i] < '0' || s[i] > '9'); i++) {
                ans << s[i];
            }
            if (s[i] == ']') { // 当前层不包含数字，不用重复，直接返回
                end = i; // 返回结束位置，方便上一层跳过当前层]之后
                return ans.str();
            } else {
                stringstream numStr;
                for (; s[i] >= '0' && s[i] <= '9'; i++) {
                    numStr << s[i];
                }
                int rep = atoi(numStr.str().c_str()); // 重复次数转成整数
                int end = 0;
                i++; // 跳过局部的[符号
                string sub = recu(s, i, end); // 递归获取局部解码
                // cout << "rep: " << rep << ", i: " << i << ", end: " << end  << ", sub: " << sub << endl;
                for (int r = 0; r < rep; r++) {
                    ans << sub; // 重复生成局部解码
                }
                i = end + 1; // 跳过局部的]符号
            }
        }
        end = i; // 返回结束位置，方便上一层跳过当前层]之后
        return ans.str();
    }

    string decodeString(string s) {
        string str = s + "]"; // 为最外层添加一个终止条件
        int end = 0;
        return recu(str, 0, end);
    }
};

int main() {
    string ans = Solution().decodeString("2[abc]3[cd]ef");
    cout << ans << endl;
}