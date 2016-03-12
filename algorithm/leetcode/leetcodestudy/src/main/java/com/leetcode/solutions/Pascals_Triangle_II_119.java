package com.leetcode.solutions;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by zwj on 2016/3/12.
 */
public class Pascals_Triangle_II_119 {
    public List<List<Integer>> generate(int numRows) {

        List<List<Integer>> results = new ArrayList<>();
        List<Integer> last = new ArrayList<>();
        if (numRows < 1) {
            return results;
        }
        results.add(Arrays.asList(1));

        if (numRows == 1) {
            return results;
        }
        last.add(1);
        last.add(1);
        results.add(last);

        for (int i = 3; i <= numRows; i++) {
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
}
