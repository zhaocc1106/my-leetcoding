/**
 * https://leetcode-cn.com/problems/roman-to-integer/
 */

package com.company;

public class romanToInt {
    public static int romanToInt(String s) {
        int res = 0;
        int i = 0;
        int j = 0;
        while (i < s.length()) {
            char curChar = s.charAt(i);
            if (curChar == 'M') {
                for (j = i; j < s.length(); j++) {
                    if (s.charAt(j) == 'M') {
                        res += 1000;
                    } else {
                        break;
                    }
                }
                i = j;
            } else if (curChar == 'D') {
                res += 500;
                i++;
            } else if (curChar == 'C' && i + 1 < s.length() && s.charAt(i + 1) == 'M') {
                res += 900;
                i += 2;
            } else if (curChar == 'C' && i + 1 < s.length() && s.charAt(i + 1) == 'D') {
                res += 400;
                i += 2;
            } else if (curChar == 'C') {
                for (j = i; j < s.length(); j++) {
                    if (s.charAt(j) == 'C') {
                        res += 100;
                    } else {
                        break;
                    }
                }
                i = j;
            } else if (curChar == 'L') {
                res += 50;
                i++;
            } else if (curChar == 'X' && i + 1 < s.length() && s.charAt(i + 1) == 'C') {
                res += 90;
                i += 2;
            } else if (curChar == 'X' && i + 1 < s.length() && s.charAt(i + 1) == 'L') {
                res += 40;
                i += 2;
            } else if (curChar == 'X') {
                for (j = i; j < s.length(); j++) {
                    if (s.charAt(j) == 'X') {
                        res += 10;
                    } else {
                        break;
                    }
                }
                i = j;
            } else if (curChar == 'V') {
                res += 5;
                i++;
            } else if (curChar == 'I' && i + 1 < s.length() && s.charAt(i + 1) == 'X') {
                res += 9;
                i += 2;
            } else if (curChar == 'I' && i + 1 < s.length() && s.charAt(i + 1) == 'V') {
                res += 4;
                i += 2;
            } else if (curChar == 'I') {
                for (j = i; j < s.length(); j++) {
                    if (s.charAt(j) == 'I') {
                        res += 1;
                    } else {
                        break;
                    }
                }
                i = j;
            }
        }
        return res;
    }

}
