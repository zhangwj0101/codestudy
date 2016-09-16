package com.leetcode.solutions;

/**
 * Created by zwj on 2016/9/5.
 */

import java.io.*;


import java.util.*;


class Test {


}


public class Main


{


    public static void main(String args[])


    {

        Scanner cin = new Scanner(System.in);
        int n, m;
        while (cin.hasNextInt()) {
            n = cin.nextInt();
            m = cin.nextInt();
            List<Integer> pricelist = new ArrayList<Integer>();
            for (int i = 0; i < n; i++) {
                pricelist.add(cin.nextInt());
            }
            HashMap<String, Integer> filelist = new HashMap<String, Integer>();
            cin.nextLine();
            for (int i = 0; i < m; i++) {

                String line = cin.nextLine();

                if (!filelist.containsKey(line)) {

                    filelist.put(line, 0);

                }
                filelist.put(line, filelist.get(line) + 1);
            }

            List<Integer> endlist = new ArrayList<Integer>();

            for (String key : filelist.keySet()) {

                endlist.add(filelist.get(key));
            }
            Collections.sort(pricelist);
            Collections.sort(endlist);
            int min = 0, max = 0;

            for (int i = 0; i < endlist.size(); i++) {
                min += endlist.get(endlist.size() - 1 - i) * pricelist.get(i);
                max += endlist.get(endlist.size() - 1 - i) * pricelist.get(pricelist.size() - 1 - i);
            }

            System.out.println(min + " " + max);

        }

    }

}

