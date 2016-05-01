package com.leetcode.solutions;

import java.util.ArrayList;
import java.util.Stack;

/**
 * Created by zhangwj on 16/3/2.
 */
public class Simplify_Path_71 {
    public static void main(String[] args) {
        Simplify_Path_71 sim = new Simplify_Path_71();
        System.out.println(sim.simplifyPath("/.../"));
    }

    public String simplifyPath(String path) {
        Stack<String> res = new Stack<String>();
        String[] ps = path.split("/");
        for (String a : ps) {
            if (a.equals("..")) {
                if (!res.empty()) {
                    res.pop();
                }
            } else if (a.equals(".") || a.equals("")) {
                continue;
            } else {
                res.push(a);
            }
        }
        if (res.empty()) {
            return "/";
        } else {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < res.size(); ++i)
                sb.append("/" + res.get(i));
            return sb.toString();
        }
    }

    public String simplifyPath1(String path) {
        String result = "/";
        String[] stubs = path.split("/+");
        ArrayList<String> paths = new ArrayList<String>();
        for (String s : stubs) {
            if (s.equals("..")) {
                if (paths.size() > 0) {
                    paths.remove(paths.size() - 1);
                }
            } else if (!s.equals(".") && !s.equals("")) {
                paths.add(s);
            }
        }
        for (String s : paths) {
            result += s + "/";
        }
        if (result.length() > 1)
            result = result.substring(0, result.length() - 1);
        return result;
    }
}
