/**
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
 */

package com.company;

import java.util.*;

public class letterCombinations {

    public static Map<Character, String> letterMap = new HashMap<Character, String>() {{
        put('2', "abc");
        put('3', "def");
        put('4', "ghi");
        put('5', "jkl");
        put('6', "mno");
        put('7', "pqrs");
        put('8', "tuv");
        put('9', "wxyz");
    }};

//    /**
//     * Get all letters of current number.
//     *
//     * @param num
//     */
//    public static char[] getCharArray(char num) {
//        if (num == '2') {
//            return new char[]{'a', 'b', 'c'};
//        } else if (num == '3') {
//            return new char[]{'d', 'e', 'f'};
//        } else if (num == '4') {
//            return new char[]{'g', 'h', 'i'};
//        } else if (num == '5') {
//            return new char[]{'j', 'k', 'l'};
//        } else if (num == '6') {
//            return new char[]{'m', 'n', 'o'};
//        } else if (num == '7') {
//            return new char[]{'p', 'q', 'r', 's'};
//        } else if (num == '8') {
//            return new char[]{'t', 'u', 'v'};
//        } else if (num == '9') {
//            return new char[]{'w', 'x', 'y', 'z'};
//        }
//        return new char[]{};
//    }

    public static List<String> resolution(String digits) {
        if (digits == null || digits.equals("")) {
            return new ArrayList<>();
        }

        List<String> subCombs = resolution(digits.substring(1)); // Get letter combinations of sub string.

        String posChars = letterMap.get(digits.charAt(0));  // Get all possible letter of first char.

        List<String> curCombs = new ArrayList<String>();
        if (subCombs == null || subCombs.size() == 0) {
            /* Is the last letter. */
            for (int i = 0; i < posChars.length(); i++) {
                curCombs.add("" + posChars.charAt(i));
            }
        } else {
            /* Add all possible char into combinations of sub string. */
            for (int i = 0; i < subCombs.size(); i++) { // Combine first char.
                for (int j = 0; j < posChars.length(); j++) {
                    curCombs.add(posChars.charAt(j) + subCombs.get(i));
                }
            }
        }
        return curCombs;
    }

    public static void main(String[] args) {
        System.out.println(resolution("23"));
    }
}