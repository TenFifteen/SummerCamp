/*
题目大意：
给定一组已经排序的区间。然后插入一个区间进去

解题思路：
遍历

遇到的问题：
没有。
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
        
        bool inserted = false;
        for (int i = 0; i < intervals.size();) {
            Interval in(0, 0);
            
            if (!inserted && newInterval.start < intervals[i].start) {
                in = newInterval;
                inserted = true;
            } else {
                in = intervals[i++];
            }
            
            if (ans.size() == 0 || ans.back().end < in.start) {
                ans.push_back(in);
            } else {
                ans.back().end = max(ans.back().end, in.end);
            }
        }
        
        if (!inserted) {
            if (ans.size() == 0 || ans.back().end < newInterval.start) {
                ans.push_back(newInterval);
            } else {
                ans.back().end = max(ans.back().end, newInterval.end);
            }
        }
        
        return ans;
    }
};