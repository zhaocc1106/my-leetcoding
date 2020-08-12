/**
 *  I. 数组中数字出现的次数
 *
 *  一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
 *
 * https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int k = 0; // 用于记录异或值
        for (auto num : nums) {
            k = k ^ num; // 将所有值做异或动作，最后的值为两个独立值的异或值。
        }

        int i = 0;
        for (; (k >> i) & 1 == 0; i++ ); // 寻找第一个为1的位

        vector<int> ans(2, 0);
        for (auto num : nums) {
            // 根据第i位分成两组，相同的值肯定在同一组，两个独立值肯定不在同一组
            if ((num >> i & 1) == 1) {
                ans[0] = ans[0] ^ num;
            } else {
                ans[1] = ans[1] ^ num;
            }
        }

        return ans;
    }
};