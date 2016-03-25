package com.leetcode.solutions;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by zwj on 2016/3/12.
 */
public class Pascals_Triangle_118 {


    public List<List<Integer>> generate(int numRows) {

        List<List<Integer>> results = new ArrayList<>();
        List<Integer> last = new ArrayList<>(0);
        if (numRows < 1) {
            return results;
        }
        results.add(Arrays.asList(1));
        if (numRows == 1) {
            return results;
        }
        for (int i = 2; i <= numRows; i++) {
            List<Integer> tempResults = new ArrayList<>(i);
            tempResults.add(1);
            for (int j = 1; j < i - 1; j++) {
                tempResults.add(last.get(j) + last.get(j - 1));
            }
            tempResults.add(1);
            results.add(tempResults);
            last = tempResults;
        }
        return results;
    }

    @Test
    public void test() {
        System.out.println(generate(10));
    }
}
