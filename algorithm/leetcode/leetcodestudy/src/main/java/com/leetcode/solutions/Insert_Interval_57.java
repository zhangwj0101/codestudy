package com.leetcode.solutions;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.ListIterator;

/**
 * Created by zhangwj on 16/2/25.
 */

public class Insert_Interval_57 {

    public static void main(String[] args) {
        Interval s1 = new Interval(1, 5);
        Interval s2 = new Interval(0, 3);
        List<Interval> intervals = new ArrayList<>();
        intervals.add(s1);
        System.out.println(insert(intervals, s2));
    }

    public static ArrayList<Interval> insert(List<Interval> intervals, Interval newInterval) {

        ArrayList<Interval> result = new ArrayList<Interval>();

        for (Interval interval : intervals) {
            if (interval.end < newInterval.start) {
                result.add(interval);
            } else if (interval.start > newInterval.end) {
                result.add(newInterval);
                newInterval = interval;
            } else if (interval.end >= newInterval.start || interval.start <= newInterval.end) {
                newInterval = new Interval(Math.min(interval.start, newInterval.start), Math.max(newInterval.end, interval.end));
            }
        }

        result.add(newInterval);

        return result;
    }
}
