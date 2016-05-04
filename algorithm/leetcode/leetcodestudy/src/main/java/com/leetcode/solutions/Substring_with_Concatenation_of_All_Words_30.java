/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.leetcode.solutions;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @author zhangwj
 */
public class Substring_with_Concatenation_of_All_Words_30 {

    public static void main(String[] args) {
        String s = "barfoofoobarthefoobarman";
        String[] words = {"foo", "bar", "the"};
        System.out.println(findSubstring(s, words));
    }

    public static List<Integer> findSubstring(String s, String[] words) {
        List<Integer> ret = new ArrayList<>();
        if (words.length <= 0 || s.length() <= 0) {
            return ret;
        }
        Map<String, Integer> wordMaps = new HashMap<>();
        for (String word : words) {
            wordMaps.put(word, wordMaps.containsKey(word) ? wordMaps.get(word) + 1 : 1);
        }
        int wordLen = words[0].length();
        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int count = 0;
            Map<String, Integer> twordMaps = new HashMap<>();
            for (int j = i; j <= s.length() - wordLen; j += wordLen) {
                String temp = s.substring(j, j + wordLen);
                if (wordMaps.containsKey(temp)) {
                    twordMaps.put(temp, twordMaps.containsKey(temp) ? twordMaps.get(temp) + 1 : 1);
                    if (twordMaps.get(temp) <= wordMaps.get(temp)) {
                        count++;
                    } else {
                        while (twordMaps.get(temp) > wordMaps.get(temp)) {
                            String tem = s.substring(left, left + wordLen);
                            twordMaps.put(tem, twordMaps.get(tem) - 1);
                            if (twordMaps.get(tem) < wordMaps.get(tem)) {
                                count--;
                            }
                            left += wordLen;
                        }
                    }
                    if (count == words.length) {
                        ret.add(left);
                        String tem = s.substring(left, left + wordLen);
                        twordMaps.put(tem, twordMaps.get(tem) - 1);
                        count--;
                        left += wordLen;
                    }
                } else {
                    count = 0;
                    twordMaps.clear();
                    left = j + wordLen;
                }
            }
        }
        return ret;
    }
}
