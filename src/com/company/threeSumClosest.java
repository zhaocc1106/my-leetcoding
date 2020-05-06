/**
 * https://leetcode-cn.com/problems/3sum-closest/
 */

package com.company;

import java.util.Arrays;

public class threeSumClosest {

    public static int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int clo_sum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.length; i++) {
            int start = i + 1;
            int end = nums.length - 1;
            while (start < end) {
                int sum = nums[start] + nums[end] + nums[i];
                if (Math.abs(target - sum) < Math.abs(target - clo_sum))
                    clo_sum = sum;
                if (sum > target)
                    end--;
                else if (sum < target)
                    start++;
                else
                    return clo_sum;
            }
        }
        return clo_sum;
    }
}
