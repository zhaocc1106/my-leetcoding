/**
 * 打开转盘锁
 * https://leetcode-cn.com/problems/open-the-lock/
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
     * 在某一位上加1，如果超过9，则转成0
     * @param src 原始字符串，4位数字
     * @param i 哪一位上加一
     * return 加一后的字符串
     */
    static string plusOne(string src, int i) {
        if (src[i] == '9') {
            src[i] = '0';
        } else {
            src[i] = src[i] + 1;
        }
        return src;
    }

    /**
    * 在某一位上减1，如果小于0，则转成9
    * @param src 原始字符串，4位数字
    * @param i 哪一位上减一
    * return 减一后的字符串
    */
    static string minusOne(string src, int i) {
        if (src[i] == '0') {
            src[i] = '9';
        } else {
            src[i] = src[i] - 1;
        }
        return src;
    }

    static int openLock(vector<string> &deadends, string target) {
        unordered_set<string> visited; // 记录所有已经访问过的路径
        unordered_set<string> deadendsSet(deadends.begin(), deadends.end()); // 记录所有的死锁路劲

        queue<string> keys;
        keys.push("0000");
        visited.insert("0000");

        int steps = 0;
        while (!keys.empty()) {
            int len = keys.size();
            for (int i = 0; i < len; i++) {
                string key = keys.front();
                cout << key << endl;
                keys.pop();

                if (deadendsSet.count(key) > 0) {
                    continue;
                }

                // 是否是解锁密码
                if (key == target) {
                    return steps;
                }

                for (int j = 0; j < 4; j++) { // 四个密钥位
                    string plusKey = plusOne(key, j);
                    if (visited.count(plusKey) == 0) { // 如果已经访问过，则跳过
                        keys.push(plusKey); // 将新生成的密钥放到下一批检查里
                        visited.insert(plusKey);
                    }
                    string minusKey = minusOne(key, j);
                    if (visited.count(minusKey) == 0) { // 如果已经访问过，则跳过
                        keys.push(minusKey); // 将新生成的密钥放到下一批检查里
                        visited.insert(minusKey);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

int main() {
    vector<string> deadends{"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
    cout << Solution::openLock(deadends, "8888") << endl;
}