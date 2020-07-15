/**
 * https://leetcode-cn.com/problems/container-with-most-water/
 */

package com.company;

public class maxArea {
    public static int maxArea(int[] height) {
        int areaSize = 0;
        for (int i = 0; i < height.length; i++) {
            for (int j = i + 1; j < height.length; j++) {
                int min = height[i] < height[j] ? height[i] : height[j];
                int size = min * (j - i);
                if (size > areaSize) {
                    areaSize = size;
                }
            }
        }
        return areaSize;
    }
}
