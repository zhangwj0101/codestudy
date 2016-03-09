package com.leetcode.solutions;

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
}
