/*
题目：22 % 插入区间 容易

题目大意：
给定一组排序并且没有交叉的区间，插入一个新的区间，有必要的话，就将重叠的区间进行合并。

解题思路：
直接遍历求解

遇到的问题：
没有问题。
*/
/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        vector<Interval> ans;
        bool isInserted = false;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i].end < newInterval.start) {
                ans.push_back(intervals[i]);
            } else if (intervals[i].start > newInterval.end) {
                if (!isInserted) {
                    ans.push_back(newInterval);
                    isInserted = true;
                }
                ans.push_back(intervals[i]);
            } else {
                newInterval.start = min(intervals[i].start, newInterval.start);
                newInterval.end = max(intervals[i].end, newInterval.end);
            }
        }
        if (!isInserted) {
            ans.push_back(newInterval);
        }
        return ans;
    }
};
