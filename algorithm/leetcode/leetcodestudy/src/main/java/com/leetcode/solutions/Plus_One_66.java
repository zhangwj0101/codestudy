package com.leetcode.solutions;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.channels.Selector;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by zhangwj on 16/3/1.
 */
public class Plus_One_66 {
    public static void main(String[] args) throws IOException {

    }

    public int[] plusOne(int[] digits) {

        int left = 0;
        digits[digits.length - 1] += 1;
        for (int i = digits.length - 1; i >= 0; i--) {
            int temp = digits[i] + left;
            digits[i] = temp % 10;
            left = temp / 10;
        }
        if (left != 0) {
            int[] nums = new int[digits.length + 1];
            nums[0] = left;
            for (int i = 1; i < nums.length; i++) {
                nums[i] = digits[i - 1];
            }
            return nums;
        } else {
            return digits;
        }
    }

    public int[] plusOne1(int[] digits) {

        if (digits == null) {
            return null;
        }
        List<Integer> sb = new ArrayList<>();
        int left = 1;
        for (int i = digits.length - 1; i >= 0; i--) {
            int temp = left + digits[i];
            sb.add(0, temp % 10);
            left = temp / 10;
        }
        if (left > 0) {
            sb.add(0, left);
        }
        int[] results = new int[sb.size()];
        for (int i = 0; i < sb.size(); i++) {
            results[i] = sb.get(i);
        }
        return results;
    }
}
