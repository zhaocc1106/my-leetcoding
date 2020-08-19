/**
 * 构建乘积数组
 *
 * 给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
 *
 * https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int> &a) {
        if (a.size() <= 1) {
            return {};
        }

        int m = a.size();
        vector<int> aLeft(m);
        vector<int> aRight(m);
        vector<int> ans(m);

        aLeft[0] = 1;
        for (int i = 1; i <= m - 1; i++) {
            aLeft[i] = aLeft[i - 1] * a[i - 1];
        }

        aRight[m - 1] = 1;
        ans[m - 1] = aRight[m - 1] * aLeft[m - 1];
        for (int i = m - 2; i >= 0; i--) {
            aRight[i] = aRight[i + 1] * a[i + 1];
            ans[i] = aRight[i] * aLeft[i];
        }

        return ans;
    }
};