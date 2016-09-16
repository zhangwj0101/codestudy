package com.leetcode.solutions;

/**
 * Created by zhangwj on 16/3/16.
 */
public class Sum_Root_to_Leaf_Numbers_129 {

    /**
     * 递归求解
     *
     * @param node
     * @param pre
     * @return
     */
    public int get(TreeNode node, int pre) {
        if (node == null) {
            return 0;
        }
        int left = 0;
        int right = 0;
        pre = pre * 10 + node.val;
        if (node.left == null && node.right == null) {
            return pre;
        }
        return get(node.left, pre) + get(node.right, pre);
    }


    public int sumNumbers(TreeNode node) {

        return get(node, 0);
    }

}
