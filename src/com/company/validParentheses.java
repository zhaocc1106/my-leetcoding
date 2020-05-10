/**
 * https://leetcode-cn.com/problems/valid-parentheses/
 */

package com.company;

public class validParentheses {

    public static int glbIdx = 0; // Save global index.


    public static boolean isValid(String str) {
        if (str.length() == 0) {
            return true;
        }
        if (str.length() % 2 != 0) {
            /* 奇数长度肯定不成对 */
            return false;
        }

        if (glbIdx == str.length() - 1) {
            /* 最后一个字符，返回上一层用于配对 */
            System.out.println(1);
            return true;
        }

        char curChar = str.charAt(glbIdx);
        if (curChar != '(' && curChar != '[' && curChar != '{') {
            /* 当前层如果不是左括号，则失败 */
            System.out.println(9);
            return false;
        }

        while (glbIdx < str.length() - 1) {
            curChar = str.charAt(glbIdx);
            if (curChar == '(' || curChar == '[' || curChar == '{') {
                char nextChar = str.charAt(++glbIdx);
                if (nextChar == '(' || nextChar == '[' || nextChar == '{') {
                    /* 如果下一个字符仍为左括号，则进入下一层 */
                    if (isValid(str)) {
                        /* 下一层配对成功，拿新的下一个字符做配对 */
                        char newChar = str.charAt(glbIdx);
                        if ((curChar == '(' && newChar == ')') || (curChar == '[' && newChar == ']')
                                || (curChar == '{' && newChar == '}')) {
                            glbIdx++;
                            System.out.println(2 + "-" + glbIdx);
                        } else {
                            System.out.println(8);
                            return false;
                        }
                    } else {
                        /* 下一层配对失败，直接返回失败 */
                        System.out.println(3);
                        return false;
                    }
                } else if ((curChar == '(' && nextChar == ')') || (curChar == '[' && nextChar == ']')
                        || (curChar == '{' && nextChar == '}')) {
                    /* 当前层配对成功，迭代下一个字符 */
                    glbIdx++;
                    System.out.println(4 + "-" + glbIdx);
                } else {
                    /* 当前层配对失败，直接返回失败 */
                    System.out.println(5);
                    return false;
                }
            } else {
                /* 当前字符是右括号，返回上一层做配对 */
                System.out.println(6);
                return true;
            }
        }
        /* 该层全部配对成功 */
        System.out.println(7);
        return true;
    }

    public static void main(String[] args) {
        System.out.println(isValid("{[[{}{}[]]]}"));
    }
}
