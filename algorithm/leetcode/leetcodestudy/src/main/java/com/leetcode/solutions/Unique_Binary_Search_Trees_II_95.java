package com.leetcode.solutions;

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by zhangwj on 16/3/9.
 */
public class Unique_Binary_Search_Trees_II_95 {

    @Test
    public void test() {
        Unique_Binary_Search_Trees_II_95 un = new Unique_Binary_Search_Trees_II_95();
        System.out.println(un.generateTrees(0).size());
    }

    public List<TreeNode> get(int left, int right) {
        List<TreeNode> res = new ArrayList<>();
        if (left <= right) {
            for (int i = left; i <= right; i++) {
                List<TreeNode> l = get(left, i - 1);
                List<TreeNode> r = get(i + 1, right);
                for (TreeNode ll : l) {
                    for (TreeNode lr : r) {
                        TreeNode s = new TreeNode(i);
                        s.left = ll;
                        s.right = lr;
                        res.add(s);
                    }
                }
            }
        } else {
            res.add(null);
        }
        return res;
    }

    public List<TreeNode> generateTrees(int n) {
        if (n == 0) {
            return new ArrayList<>();
        }
        return get(1, n);
    }
}
