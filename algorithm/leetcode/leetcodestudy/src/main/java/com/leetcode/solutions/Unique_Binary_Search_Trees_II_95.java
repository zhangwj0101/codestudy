package com.leetcode.solutions;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by zhangwj on 16/3/9.
 */
public class Unique_Binary_Search_Trees_II_95 {

    public static void main(String[] args) {
        Unique_Binary_Search_Trees_II_95 un = new Unique_Binary_Search_Trees_II_95();
        System.out.println(un.generateTrees(3).size());
    }

    public List<TreeNode> merge(List<TreeNode> l, List<TreeNode> r, int i) {
        List<TreeNode> res = new ArrayList<>();

        if (l == null && r != null) {
            for (TreeNode rt : r) {
                TreeNode s = new TreeNode(i);
                s.right = rt;
                res.add(s);
            }
        } else if (l != null && r == null) {
            for (TreeNode lt : l) {
                TreeNode s = new TreeNode(i);
                s.left = lt;
                res.add(s);
            }
        } else if (l != null && r != null) {
            for (TreeNode lt : l) {
                for (TreeNode rt : r) {
                    TreeNode s = new TreeNode(i);
                    s.left = lt;
                    s.right = rt;
                    res.add(s);
                }
            }
        } else {
            TreeNode s = new TreeNode(i);
            res.add(s);
        }
        return res;
    }

    public List<TreeNode> get(int left, int right) {
        if (left <= right) {
            List<TreeNode> res = new ArrayList<>();
            for (int i = left; i <= right; i++) {
                List<TreeNode> l = get(left, i - 1);
                List<TreeNode> r = get(i + 1, right);
                res.addAll(merge(l, r, i));
            }
            return res;
        }
        return null;
    }

    public List<TreeNode> generateTrees(int n) {

        List<TreeNode> result = get(1, n);

        return result == null ? new ArrayList<TreeNode>() : result;
    }
}
