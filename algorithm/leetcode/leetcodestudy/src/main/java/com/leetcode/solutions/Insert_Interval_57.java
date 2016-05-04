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

    public static int pos(List<Interval> intervals, Interval newInterval) {
        int left = 0;
        int right = intervals.size() - 1;
        int mid = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            Interval temp = intervals.get(mid);
            if (newInterval.start >= temp.start && newInterval.start <= temp.end) {
                if (temp.end >= newInterval.end) {
                    return intervals.size() - 1;
                } else {
                    temp.end = newInterval.end;
                }
                return mid;
            } else if (newInterval.start < temp.start) {
                right = mid - 1;
            } else if (newInterval.start > temp.end) {
                left = mid + 1;
            }
        }
        intervals.add(left, newInterval);
        return left;
    }

    public static List<Interval> insert(List<Interval> intervals, Interval newInterval) {

        if (intervals.size() == 0) {
            return Arrays.asList(newInterval);
        }
        if (intervals.get(0).start > newInterval.end) {
            intervals.add(0, newInterval);
            return intervals;
        }
        int po = pos(intervals, newInterval);
        newInterval = intervals.get(po);
        ListIterator<Interval> intervalListIterator = intervals.listIterator(po + 1);
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

    public static List<Interval> insert1(List<Interval> intervals, Interval newInterval) {

        if (intervals.size() == 0) {
            return Arrays.asList(newInterval);
        }
        if (intervals.get(0).start > newInterval.end) {
            intervals.add(0, newInterval);
            return intervals;
        }
        int i = intervals.size() - 1;
        for (; i >= 0; i--) {
            Interval te = intervals.get(i);
            if (newInterval.start >= te.start && newInterval.start <= te.end) {
                if (newInterval.end <= te.end) {
                    return intervals;
                } else {
                    te.end = newInterval.end;
                    newInterval = te;
                }
                break;
            } else if (newInterval.start > te.end) {
                intervals.add(i + 1, newInterval);
                i++;
                break;
            }
        }
        if (i == -1) {
            intervals.add(0, newInterval);
            i++;
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

    public ArrayList<Interval> insert1(ArrayList<Interval> intervals, Interval newInterval) {
        if (newInterval == null || intervals == null) {
            return intervals;
        }

        ArrayList<Interval> results = new ArrayList<Interval>();
        int insertPos = 0;

        for (Interval interval : intervals) {
            if (interval.end < newInterval.start) {
                results.add(interval);
                insertPos++;
            } else if (interval.start > newInterval.end) {
                results.add(interval);
            } else {
                newInterval.start = Math.min(interval.start, newInterval.start);
                newInterval.end = Math.max(interval.end, newInterval.end);
            }
        }
        results.add(insertPos, newInterval);

        return results;
    }
}
