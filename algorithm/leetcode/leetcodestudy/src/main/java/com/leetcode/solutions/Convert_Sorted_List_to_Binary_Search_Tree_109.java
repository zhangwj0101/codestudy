package com.leetcode.solutions;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by zhangwj on 16/3/10.
 */
public class Convert_Sorted_List_to_Binary_Search_Tree_109 {
    public TreeNode build(List<Integer> nums, int left, int right) {
        if (left <= right) {
            int mid = (left + right) / 2;
            TreeNode root = new TreeNode(nums.get(mid));
            root.left = build(nums, left, mid - 1);
            root.right = build(nums, mid + 1, right);
            return root;
        }
        return null;
    }

    public TreeNode sortedListToBST(ListNode head) {

        List<Integer> nums = new ArrayList<>();
        while (head != null) {
            nums.add(head.val);
            head = head.next;
        }
        return build(nums, 0, nums.size() - 1);
    }
}
