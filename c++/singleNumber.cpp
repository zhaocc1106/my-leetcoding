/**
 * 数组中每个数会出现3次，只有1个例外的数仅出现1次，找到这个数
 * https://blog.csdn.net/ojshilu/article/details/14762791
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int singleValue(vector<int> arr) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (auto item : arr) {
                sum += ((item >> i) & 1);
            }
            if (sum % 3 == 1) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> arr {1, 1, 1, 3, 2, 2, 2};
    cout << Solution::singleValue(arr) << endl;
}