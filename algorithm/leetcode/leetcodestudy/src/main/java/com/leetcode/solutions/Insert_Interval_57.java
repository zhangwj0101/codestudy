package com.leetcode.solutions;

import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;

/**
 * Created by zhangwj on 16/2/25.
 */

public class Insert_Interval_57 {

    public static void main(String[] args) {
        Interval s1 = new Interval(1, 5);
        Interval s2 = new Interval(2, 3);
        List<Interval> intervals = new ArrayList<>();
        intervals.add(s1);
        System.out.println(insert(intervals, s2));
    }

    public int pos(List<Interval> intervals, Interval newInterval) {
        int left = 0;
        int right = intervals.size() - 1;
        int diff = 0;
        int mid = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            Interval temp = intervals.get(mid);
            diff = temp.start - newInterval.start;
            if (diff == 0) {
                return mid;
            } else if (diff > 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }

    public static List<Interval> insert(List<Interval> intervals, Interval newInterval) {

        if (newInterval == null) {
            return intervals;
        }
        if (intervals.size() == 0) {
            List<Interval> results = new ArrayList<>();
            results.add(newInterval);
            return results;
        }

        if (intervals.get(0).start > newInterval.end) {
            intervals.add(0, newInterval);
            return intervals;
        }
        if (intervals.get(intervals.size() - 1).end < newInterval.start) {
            intervals.add(newInterval);
            return intervals;
        }
        int i = intervals.size() - 1;
        boolean finsert = false;
        for (; i >= 0; i--) {
            Interval te = intervals.get(i);
            if (newInterval.start >= te.start && newInterval.start <= te.end) {
                if (newInterval.end <= te.end) {
                    return intervals;
                } else {
                    te.end = newInterval.end;
                }
                break;
            } else if (newInterval.start > te.end) {
                intervals.add(i + 1, newInterval);
                i++;
                break;
            }
        }
        ListIterator<Interval> intervalListIterator = intervals.listIterator(i + 1);
        while (intervalListIterator.hasNext()) {
            Interval te = intervalListIterator.next();
            if (newInterval.end < te.start) {
                break;
            } else if (newInterval.end <= te.end) {
                newInterval.end = te.end;
                intervalListIterator.remove();
                break;
            } else {
                intervalListIterator.remove();
            }
        }
        return intervals;
    }
}
