/**
 * https://leetcode-cn.com/problems/zigzag-conversion/
 */

package com.company;

public class zconvert {

    public static String convert(String s, int numRows) {
        if (s == null || s.equals("")) {
            return "";
        }
        // System.out.println("s: " + s + " numRows: " + numRows);
        // System.out.println(s.length());
        int len = s.length();
        if (len == 1 || numRows == 1) {
            return s;
        }

        char[] zStr = new char[len];
        int curInd = 0;
        int firstDelta = (numRows - 1) * 2;
        for (int i = 0; i < numRows; i++) {
            // System.out.println("i: " + i);
            int curDelta = (numRows - i - 1) * 2;
            for (int j = i; j < len && curInd < len;) {
                // System.out.println("j: " + j + ", curDelta: " + curDelta);
                zStr[curInd] = s.charAt(j);
                curInd++;
                if (curDelta == 0 || curDelta == firstDelta) {
                    j += firstDelta;
                } else {
                    j += curDelta;
                    curDelta = firstDelta - curDelta;
                }
            }
        }
        return new String(zStr);
    }

    public static void main(String[] args) {
        System.out.println(convert("leetcodeishiring", 5));
    }
}
