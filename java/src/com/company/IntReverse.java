/**
 * https://leetcode-cn.com/problems/reverse-integer/
 */

package com.company;

public class IntReverse {

    public static int reverse(int x) {
        if (x == 0) {
            return 0;
        }

        long rev = 0; // Save reverse.

        boolean neg = x < 0; // If is negative.
        if (neg) {
            // change to positive.
            x = -x;
        }

        for (; x > 0; x /= 10) {
            rev = rev * 10 + x % 10;
        }

        if (neg) {
            rev = -rev;
        }

        if (rev > 0x7fffffff || rev < 0x80000000) {
            return 0;
        }

        return (int) rev;
    }

    public static void main(String[] args) {
        System.out.println(reverse(2147483647));
    }
}
