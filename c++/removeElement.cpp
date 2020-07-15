/**
 *https://leetcode-cn.com/problems/remove-element/
 */

#include <iostream>
#include <vector>

using namespace std;

class resolution{
public:
    static int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i+1;
    }
};