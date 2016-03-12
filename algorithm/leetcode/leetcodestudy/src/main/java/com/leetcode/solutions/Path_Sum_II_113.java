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

    public boolean get(TreeNode node, int subsum, int sum, List<List<Integer>> results, List<Integer> temp) {
        temp.add(node.val);
        subsum += node.val;
        boolean flag = false;
        if (node.left != null && node.right != null) {
            flag = get(node.left, subsum, sum, results, temp)
                    || get(node.right, subsum, sum, results, temp);
        } else if (node.left != null && node.right == null) {
            flag = get(node.left, subsum, sum, results, temp);
        } else if (node.left == null && node.right != null) {
            flag = get(node.right, subsum, sum, results, temp);
        } else if (node.left == null && node.right == null) {
            flag = subsum == sum;
        }

        if (flag) {
            List<Integer> ts = new ArrayList<>(temp.size());
            for (Integer in : temp) {
                ts.add(in);
            }
            results.add(ts);
        }
        temp.remove(temp.size() - 1);
        return flag;
    }

    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> results = new ArrayList<>();
        if (root == null) {
            return results;
        }
        int subsum = 0;
        List<Integer> temp = new ArrayList<>();
        get(root, 0, sum, results, temp);
        System.out.println(results);
        Stack<TreeNode> stacks = new Stack<>();
        stacks.push(root);
        while (!stacks.empty()) {
            TreeNode node = stacks.pop();
            temp.add(node.val);
            if (node.right != null) {
                stacks.push(node.right);
            }
            if (node.left != null) {
                stacks.push(node.left);
            }
            if (node.left == null && node.right == null) {
                int tempsub = 0;
                List<Integer> ts = new ArrayList<>(temp.size());
                for (Integer in : temp) {
                    ts.add(in);
                    tempsub += in;
                }
                if (tempsub == sum) {
                    results.add(ts);
                }
                temp.remove(temp.size() - 1);
                temp = temp.subList(0, stacks.size());
            }

        }
        return results;
    }

}
