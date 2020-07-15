/**
 * https://leetcode-cn.com/problems/integer-to-roman/
 */

package com.company;

public class intToRoman {
    public static String intToRoman(int num) {
        StringBuilder res = new StringBuilder();
        if (num <= 3999 && num >= 1000) {
            int cur = num / 1000;
            for (int i = 0; i < cur; i++) {
                res.append('M');
            }
            num = num % 1000;
        }

        if (num < 1000 && num >= 900) {
            res.append("CM");
            num = num % 100;
        } else if (num < 900 && num >= 500) {
            res.append('D');
            int cur = (num - 500) / 100;
            for (int i = 0; i < cur; i++) {
                res.append('C');
            }
            num = num % 100;
        } else if (num < 500 && num >= 400) {
            res.append("CD");
            num = num % 100;
        } else if (num < 400 && num >= 100) {
            int cur = num / 100;
            for (int i = 0; i < cur; i++) {
                res.append('C');
            }
            num = num % 100;
        }

        if (num < 100 && num >= 90) {
            res.append("XC");
            num = num % 10;
        } else if (num < 90 && num >= 50) {
            res.append('L');
            int cur = (num - 50) / 10;
            for (int i = 0; i < cur; i++) {
                res.append('X');
            }
            num = num % 10;
        } else if (num < 50 && num >= 40) {
            res.append("XL");
            num = num % 10;
        } else if (num < 40 && num >= 10) {
            int cur = num / 10;
            for (int i = 0; i < cur; i++) {
                res.append('X');
            }
            num = num % 10;
        }

        System.out.println(num);

        if (num == 9) {
            res.append("IX");
        } else if (num < 9 && num >= 5) {
            res.append('V');
            int cur = num - 5;
            for (int i = 0; i < cur; i++) {
                res.append('I');
            }
        } else if (num == 4) {
            res.append("IV");
        } else if (num < 4 && num >= 1) {
            int cur = num;
            for (int i = 0; i < cur; i++) {
                res.append('I');
            }
        }

        return res.toString();
    }

    public static void main(String[] args) {
//        System.out.println(intToRoman(58));
//        System.out.println(intToRoman(1994));
//        System.out.println(intToRoman(41));
//        System.out.println(intToRoman(99));
        System.out.println(intToRoman(3999));
    }
}
