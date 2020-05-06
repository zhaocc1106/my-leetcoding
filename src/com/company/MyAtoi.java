/**
 * https://leetcode-cn.com/problems/string-to-integer-atoi/
 */

package com.company;

public class MyAtoi {
    public static int myAtoi(String str) {
        if (str == null || str.equals("")) {
            return 0;
        }

        int curInd = 0;
        // Find the first not none char.
        for (; curInd < str.length() && (str.charAt(curInd) == ' ' || str.charAt(curInd) == '\t'); curInd++) ;
        if (curInd >= str.length()) {
            return 0;
        }

        if ((str.charAt(curInd) > '9' || str.charAt(curInd) < '0') && str.charAt(curInd) != '-' && str.charAt(curInd) != '+') {
            return 0;
        }

        boolean neg = false;
        if (str.charAt(curInd) == '-') {
            neg = true;
            curInd++;
        } else if (str.charAt(curInd) == '+') {
            curInd++;
        }

        int res = 0;
        for (; curInd < str.length() && str.charAt(curInd) <= '9' && str.charAt(curInd) >= '0'; curInd++) {
            byte curByte = (byte) str.charAt(curInd);
            curByte -= 48;
            if (neg) {
                if ((res < Integer.MIN_VALUE / 10)|| (res == Integer.MIN_VALUE / 10 && curByte > 8)) {
                    return 0x80000000;
                }
                res = res * 10 - (((byte) str.charAt(curInd)) - 48);
            } else {
                if ((res > Integer.MAX_VALUE / 10) || (res == Integer.MAX_VALUE / 10 && curByte > 7)) {
                    return 0x7fffffff;
                }
                res = res * 10 + (((byte) str.charAt(curInd)) - 48);
            }
        }

        return res;
    }

    public static void main(String[] args) {
        System.out.println(myAtoi("4193 with words"));
    }
}
