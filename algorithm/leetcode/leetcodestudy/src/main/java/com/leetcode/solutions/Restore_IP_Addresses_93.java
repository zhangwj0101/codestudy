package com.leetcode.solutions;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by zhangwj on 16/3/8.
 */
public class Restore_IP_Addresses_93 {

    public static void main(String[] args) {
        Restore_IP_Addresses_93 r = new Restore_IP_Addresses_93();
        List<String> res = r.restoreIpAddresses("25525511135");
        System.out.println(res);
    }

    private boolean isValid(String s) {
        Integer a = new Integer(Integer.parseInt(s));
        return a.toString().compareTo(s) == 0 && a < 256;
    }

    public List<String> restoreIpAddresses(String s) {
        int len = s.length();
        List<String> ret = new ArrayList<String>();
        for (int i = 1; i < 4 && i < len - 2; ++i) {
            for (int j = 1; j < 4 && i + j < len - 1; ++j)
                for (int k = 1; k < 4 && i + j + k < len; ++k) {
                    String s1 = s.substring(0, i);
                    String s2 = s.substring(i, i + j);
                    String s3 = s.substring(i + j, i + j + k);
                    String s4 = s.substring(i + j + k);
                    if (s4.length() > 3)
                        continue;
                    if (isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4))
                        ret.add(s1 + "." + s2 + "." + s3 + "." + s4);
                }
        }
        return ret;
    }

    public List<String> restoreIpAddresses1(String s) {
        if (s == null) {
            return null;
        }

        List<String> ret = new ArrayList<>();
        List<String> path = new ArrayList<>();

        dfs(s, 0, path, ret);
        return ret;
    }

    public void dfs(String s, int index, List<String> path, List<String> ret) {
        if (path.size() == 4) {
            if (index == s.length()) {
                StringBuilder sb = new StringBuilder();
                for (String str : path) {
                    sb.append(str);
                    sb.append('.');
                }
                sb.deleteCharAt(sb.length() - 1);
                ret.add(sb.toString());
            }
            return;
        }

        int len = s.length();
        for (int i = index; i < index + 3 && i < len; i++) {
            if (s.charAt(index) == '0' && i > index) {
                break;
            }
            String pre = s.substring(index, i + 1);
            int num = Integer.parseInt(pre);
            if (num > 255) {
                continue;
            }
            path.add(pre);
            dfs(s, i + 1, path, ret);
            path.remove(path.size() - 1);
        }
    }
}
