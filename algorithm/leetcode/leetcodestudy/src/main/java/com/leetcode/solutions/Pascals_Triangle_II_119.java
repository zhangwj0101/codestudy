package com.leetcode.solutions;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by zwj on 2016/3/12.
 */
public class Pascals_Triangle_II_119 {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> results = new ArrayList<>();
        if (rowIndex < 1) {
            return Arrays.asList(1);
        }
        int[] temp = new int[rowIndex + 1];
        Arrays.fill(temp, 1);
        for (int i = 1; i < rowIndex; i++) {
            for (int j = i; j >= 1; j--) {
                temp[j] += temp[j - 1];
            }
        }
        for (int i = 0; i <= rowIndex; i++) {
            results.add(temp[i]);
        }
        return results;
    }

    @Test
    public void get() {
        System.out.println(getRow(5));
    }


}
