package com.leetcode.solutions;


import java.util.*;
import java.util.List;

/**
 * Created by zhangwj on 16/2/25.
 */
public class Group_Anagrams_49 {

    public static void main(String[] args) {

        String[] strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
        System.out.println(groupAnagrams(strs));
    }

    public static List<List<String>> groupAnagrams(String[] strs) {

        List<List<String>> results = new ArrayList<>();
        if (strs.length < 1) {
            return results;
        }
        Arrays.sort(strs);
        Map<String, List<String>> maps = new HashMap<>();
        for (String t : strs) {
            char[] chs = t.toCharArray();
            Arrays.sort(chs);
            String temp = String.valueOf(chs);
            if (maps.containsKey(temp)) {
                maps.get(temp).add(t);
            } else {
                List<String> ts = new ArrayList<String>();
                ts.add(t);
                maps.put(temp, ts);
            }
        }
        results.addAll(maps.values());

        return results;
    }
}
