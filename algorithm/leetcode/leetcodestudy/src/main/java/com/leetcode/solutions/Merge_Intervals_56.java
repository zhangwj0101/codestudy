package com.leetcode.solutions;

import java.util.*;

/**
 * Created by zhangwj on 16/2/25.
 */
public class Merge_Intervals_56 {

    public static void main(String[] args) {
        List<Interval> results = new ArrayList<>();
        Interval s1 = new Interval(1, 3);
        Interval s2 = new Interval(2, 6);
        Interval s3 = new Interval(8, 10);
        Interval s4 = new Interval(15, 18);
        results.add(s1);
        results.add(s2);
        results.add(s3);
        results.add(s4);
        System.out.println(new Merge_Intervals_56().merge(results));
    }


    public List<Interval> merge(List<Interval> intervals) {
        List<Interval> results = new ArrayList<>();
        if (intervals.size() == 0) {
            return results;
        }
        Collections.sort(intervals, new Comparator<Interval>() {
            @Override
            public int compare(Interval o1, Interval o2) {
                return o1.start - o2.start;
            }
        });
        results.add(intervals.get(0));
        ListIterator<Interval> intervalListIterator = intervals.listIterator(1);
        while (intervalListIterator.hasNext()) {
            Interval t = intervalListIterator.next();
            Interval re = results.get(results.size() - 1);
            if (t.start >= re.start && t.start <= re.end) {
                re.start = Math.min(re.start, t.start);
                re.end = Math.max(re.end, t.end);
            } else {
                results.add(t);
            }
        }
        return results;
    }
}

class Interval {
    int start;
    int end;

    Interval() {
        start = 0;
        end = 0;
    }

    Interval(int s, int e) {
        start = s;
        end = e;
    }

    @Override
    public String toString() {
        return "[" + start +
                "," + end +
                ']';
    }
}
