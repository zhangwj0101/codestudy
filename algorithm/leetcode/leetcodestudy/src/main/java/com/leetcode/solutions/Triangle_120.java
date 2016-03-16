package com.leetcode.solutions;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * Created by zwj on 2016/3/12.
 */
public class Triangle_120 {
    public int minimumTotal(List<List<Integer>> triangle) {
        if (triangle == null || triangle.size() == 0) {
            return 0;
        }

        int rows = triangle.size();
        int[] D = new int[rows];

        for (int i = rows - 1; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                if (i == rows - 1) {
                    D[j] = triangle.get(i).get(j);
                } else {
                    D[j] = triangle.get(i).get(j) + Math.min(D[j], D[j + 1]);
                }
            }
        }

        return D[0];
    }


}
