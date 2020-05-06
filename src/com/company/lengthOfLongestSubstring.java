/**
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 */

package com.company;

public class lengthOfLongestSubstring {

    // If has repeated item in string.
    public static boolean hasRepeat(String s) {
        System.out.println("hasRepeat: " + s);
        int len = s.length();
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (s.charAt(i) == s.charAt(j)) {
                    return true;
                }
            }
        }
        return false;
    }

    public static int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }

        int len = s.length();
        int maxNoRepeat = 1;
        for (int i = 0; i < len; ++i) {
            if (len - i <= maxNoRepeat) {
                // Left substr length has been smaller than maxNoRepeat. Don't need iter next substr.
                break;
            }

            for (int j = i + maxNoRepeat + 1; j < len + 1; ++j) {
                String subStr = s.substring(i, j);
                if (!hasRepeat(subStr)) {
                    if (maxNoRepeat < j - i) {
                        maxNoRepeat = j - i;
                    }
                    System.out.println(maxNoRepeat);
                } else {
                    // Already has repeated item. Enter next start item.
                    break;
                }
            }
        }

        return maxNoRepeat;
    }

    public static void main(String[] args) {
        String str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\\\"#$%&'()*+,-./:;<=>?@[\\\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\\\"#$%&'()*+,-./:;<=>?@[\\\\]^_`{|}~";
        System.out.println(lengthOfLongestSubstring(str));
    }
}
