/**
 * https://leetcode-cn.com/problems/longest-palindromic-substring/
 */

package com.company;

public class longestPalindrome {

    public static String longestPalindrome(String s) {
        if (s == null || s.equals("")) {
            return "";
        }

        int len = s.length();
        int palBegin = 0; // The palindrome string begin index.
        int palEnd = 0; // The palindrome string end index.

        for (int i = 0; i < len - 1; i++) {
            if (palEnd - palBegin + 1 >= len - i) {
                // The left str is smaller than palindrome len.
                break;
            }
            System.out.println(s.substring(i));
            System.out.println("i: " + i);

            /* The palindrome begin, half and end index for current iteration. */
            int begin = i;
            int half = i;
            int end = i;

            boolean terminate = false;

            for (int j = i + 1; j < len; j++) {
                if ((len - j) * 2 <= palEnd - palBegin + 1) {
                    // The left str is smaller than palindrome len.
                    terminate = true;
                    break;
                }
                System.out.println("j: " + j);

                if (s.charAt(j) != s.charAt(half) && (j < len - 1 && s.charAt(j + 1) != s.charAt(half))) {
                    // To find the first same char.
                    half = j;
                } else {
                    if (s.charAt(j) == s.charAt(half)) {
                        // Such as "aa".
                        half = j - 1;
                        end = half + 2;
                        // Find all same char.
                        for (; end < len; end++) {
                            if (s.charAt(half) != s.charAt(end)) {
                                break;
                            }
                        }
                    } else if (j < len - 1 && s.charAt(j + 1) == s.charAt(half)) {
                        // Such as "aba"
                        half = j;
                        end = half + 1;
                    } else {
                        continue;
                    }
                    begin = half - 1;

                    if (begin < i || end >= len) {
                        begin++;
                        end--;
                        if (end - begin > palEnd - palBegin) {
                            // Found longer palindrome.
                            palBegin = begin;
                            palEnd = end;
                        }
                    } else {
                        System.out.println("[before] begin: " + begin + ", half: " + half + ", end: " + end);
                        // Find the palindrome begin and end.
                        for (; begin >= i && end < len; begin--, end++) {
                            if (s.charAt(begin) != s.charAt(end)) {
                                break;
                            }
                        }
                        begin++;
                        end--;

                        System.out.println("[end] begin: " + begin + ", half: " + half + ", end: " + end);
                        if (end - begin > palEnd - palBegin) {
                            // Found longer palindrome.
                            palBegin = begin;
                            palEnd = end;
                        }
                    }
                }
            }

            if (terminate) {
                break;
            }
        }

        System.out.println("palBegin: " + palBegin + ", palEnd: " + palEnd);

        if (palEnd == palBegin) {
            return s.substring(0, 1);
        } else {
            return s.substring(palBegin, palEnd + 1);
        }
    }

    public static void main(String[] args) {
        System.out.println("#############Find completely: " + longestPalindrome("babad"));
        System.out.println("#############Find completely: " + longestPalindrome("cbbd"));
        System.out.println("#############Find completely: " + longestPalindrome("aaa"));
        System.out.println("#############Find completely: " + longestPalindrome("ac"));
        System.out.println("#############Find completely: " + longestPalindrome("aaaa"));
        System.out.println("#############Find completely: " + longestPalindrome("ccd"));
        System.out.println("#############Find completely: " + longestPalindrome("bananas"));
        System.out.println("#############Find completely: " + longestPalindrome("aaabaaaa"));
    }
}
