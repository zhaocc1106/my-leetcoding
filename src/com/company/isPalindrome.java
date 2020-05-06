/**
 * https://leetcode-cn.com/problems/palindrome-number/
 */

package com.company;

public class isPalindrome {
    public static int reverse(int x) {
        int rev = 0;
        for (; x > 0; x = x / 10) {
            int i = x % 10;
            rev = rev * 10 + i;
        }
        return rev;
    }

    public static boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int rev = reverse(x);
        System.out.println(rev);
        return rev == x;
    }
}
