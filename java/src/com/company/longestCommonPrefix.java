/**
 * https://leetcode-cn.com/problems/longest-common-prefix/
 */

package com.company;

public class longestCommonPrefix {
    public static String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) {
            return "";
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < strs[0].length(); i++) {
            char curChar = strs[0].charAt(i);
            boolean common = true;
            for (int j = 1; j < strs.length; j++) {
                if (i < strs[j].length() && curChar == strs[j].charAt(i)) {
                    // continue.
                } else {
                    common = false;
                    break;
                }
            }
            if (common) {
                sb.append(curChar);
            } else {
                break;
            }
        }
        return sb.toString();
    }
}
