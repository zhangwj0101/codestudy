package com.leetcode.solutions;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;

/**
 * Created by zwj on 2016/3/12.
 */
public class Path_Sum_II_113 {


    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> rst = new ArrayList<>();
        List<Integer> solution = new ArrayList<Integer>();

        findSum(rst, solution, root, sum);
        return rst;
    }

    private void findSum(List<List<Integer>> result, List<Integer> solution, TreeNode root, int sum) {
        if (root == null) {
            return;
        }

        sum -= root.val;

        if (root.left == null && root.right == null) {
            if (sum == 0) {
                solution.add(root.val);
                result.add(new ArrayList<Integer>(solution));
                solution.remove(solution.size() - 1);
            }
            return;
        }

        solution.add(root.val);
        findSum(result, solution, root.left, sum);
        findSum(result, solution, root.right, sum);
        solution.remove(solution.size() - 1);
    }


}
