package com.leetcode.solutions;

import java.util.*;

/**
 * Created by zhangwj on 16/3/16.
 */
public class Word_Ladder_127 {

    /**
     * BFS方式
     *
     * @param start
     * @param end
     * @param dict
     * @return
     */
    public int ladderLength(String start, String end, Set<String> dict) {
        if (start == null || end == null || dict == null) {
            return 0;
        }
        //用于BFS时候使用
        Queue<String> q = new LinkedList<String>();
        q.offer(start);

        //存储已经遍历过的数据，防止重复遍历
        HashSet<String> set = new HashSet<String>();
        set.add(start);

        int level = 1;

        while (!q.isEmpty()) {
            int size = q.size();
            level++;
            for (int i = 0; i < size; i++) {
                String s = q.poll();
                int len = s.length();

                for (int j = 0; j < len; j++) {
                    StringBuilder sb = new StringBuilder(s);
                    for (char c = 'a'; c <= 'z'; c++) {
                        sb.setCharAt(j, c);
                        String tmp = sb.toString();

                        if (tmp.equals(end)) {
                            return level;
                        }
                        if (set.contains(tmp) || !dict.contains(tmp)) {
                            continue;
                        }
                        set.add(tmp);
                        q.offer(tmp);
                    }
                }
            }
        }
        return 0;
    }


}
