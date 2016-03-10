package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/10.
 */
public class Convert_Sorted_Array_to_Binary_Search_Tree_108 {

    public TreeNode build(int[] nums, int left, int right) {
        if (left <= right) {
            int mid = (left + right) / 2;
            TreeNode root = new TreeNode(nums[mid]);
            root.left = build(nums, left, mid - 1);
            root.right = build(nums, mid + 1, right);
            return root;
        }
        return null;
    }

    public TreeNode sortedArrayToBST(int[] nums) {
        return build(nums, 0, nums.length - 1);
    }
}
