/**
 * https://leetcode-cn.com/problems/4sum/submissions/
 */

package com.company;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class fourNumSum {

    public static List<List<Integer>> resolution(int[] nums, int target) {
        List<List<Integer>> lists = new ArrayList<List<Integer>>();
        if (nums.length < 4) {
            return lists;
        }

        Arrays.sort(nums);

        /*
        for (int num : nums) {
            System.out.print(num + ", ");
        }
        System.out.println("");
        */
        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // Skip repeat.
            }
            for (int j = i + 1; j < nums.length; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue; // Skip repeat.
                }
                int left = j + 1;
                int right = nums.length - 1;
                while (left < right) {
                    // System.out.println(nums[i] + ", " + nums[j] + ", " + nums[left] + ", " + nums[right]);
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        lists.add(Arrays.asList(nums[i], nums[j], nums[left], nums[right]));
                        while (left < nums.length - 1 && nums[left + 1] == nums[left]) {
                            left++; // Skip repeat.
                        }
                        while (right > j + 1 && nums[right - 1] == nums[right]) {
                            right--; // Skip repeat.
                        }
                        left++;
                        right--;
                    } else if (sum < target) {
                        while (left < nums.length - 1 && nums[left + 1] == nums[left]) {
                            left++; // Skip repeat.
                        }
                        left++;
                    } else {
                        while (right > j + 1 && nums[right - 1] == nums[right]) {
                            right--; // Skip repeat.
                        }
                        right--;
                    }
                }
            }
        }
        return lists;
    }

    public static void main(String[] args) {
        System.out.println(resolution(new int[]{1, 1, 0, 0, -1, -1, 0, -2, -2, 2, 2}, 0));
    }
}
