package com.leetcode.solutions;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by zhangwj on 16/3/9.
 */
public class Validate_Binary_Search_Tree_98 {


    public void valid(TreeNode root, List<Integer> nums) {

        if (root.left != null) {
            valid(root.left, nums);
        }
        nums.add(root.val);
        if (root.right != null) {
            valid(root.right, nums);
        }
    }


    public boolean isValidBST(TreeNode root) {

        if (root == null) {
            return true;
        }
        List<Integer> nums = new ArrayList<>();
        valid(root, nums);
        int i = 0;
        for (i = 0; i < nums.size() - 1 && nums.get(i) < nums.get(i + 1); i++) {

        }
        return i == nums.size() - 1;
    }
}