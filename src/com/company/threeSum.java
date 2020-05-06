/**
 * https://leetcode-cn.com/problems/3sum/
 */

package com.company;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class threeSum {

    public static List<List<Integer>> solution(int[] nums) {
        List<List<Integer>> lists = new ArrayList<List<Integer>>();
        if (nums == null || nums.length < 3) {
            return lists;
        }

        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > 0) { // If least > 0, sum can't be zero.
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // Skip repeat.
            }
            int mid = i + 1;
            int max = nums.length - 1;
            while (mid < max) {
                System.out.println(nums[i] + ", " + nums[mid] + ", " + nums[max]);
                int sum = nums[i] + nums[mid] + nums[max];
                if (sum == 0) {
                    lists.add(Arrays.asList(nums[i], nums[mid], nums[max]));
                    System.out.println("add");
                    while (mid < max && nums[mid] == nums[mid + 1]) {
                        mid++;
                    } // Skip repeat.
                    while (max > mid && nums[max] == nums[max - 1]) {
                        max--; // Skip repeat.
                    }
                    mid++;
                    max--;
                } else if (sum < 0) {
                    mid++;
                } else {
                    max--;
                }

            }
        }
        return lists;
    }

    public static void main(String[] args) {
        System.out.println("1".substring(1));
        int[] nums = {-1, -1, 0, 0, 0, 1, 2, -1, -4};
        System.out.println(solution(nums));
    }
}
