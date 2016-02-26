package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/2/25.
 */
public class Length_of_Last_Word_58 {
    public int lengthOfLastWord(String s) {
        if (s.trim().length() == 0) {
            return 0;
        }
        String[] split = s.split(" ");
        return split[split.length - 1].length();
    }
}
