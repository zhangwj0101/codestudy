package com.leetcode.solutions;

import java.util.Arrays;

/**
 * Created by zhangwj on 16/3/8.
 */
public class Scramble_String_87 {

    public static void main(String[] args) {
        Scramble_String_87 sc = new Scramble_String_87();
        System.out.println(sc.isScramble("abb", "bba"));
    }

    public boolean isScramble(String s1, String s2) {
        if (s1 == null || s2 == null || s1.length() != s2.length()) {
            return false;
        }
        if (s1.equals(s2)) {
            return true;
        }
        char[] chars1 = s1.toCharArray();
        char[] chars2 = s2.toCharArray();
        Arrays.sort(chars1);
        Arrays.sort(chars2);
        if (!Arrays.equals(chars1, chars2)) {
            return false;
        }
        for (int i = 1; i < s1.length(); ++i) {
            if (isScramble(s1.substring(0, i), s2.substring(0, i)) && isScramble(s1.substring(i), s2.substring(i))) {
                return true;
            }
            if (isScramble(s1.substring(0, i), s2.substring(s2.length() - i)) && isScramble(s1.substring(i), s2.substring(0, s2.length() - i))) {
                return true;
            }
        }
        return false;
    }

}
