/*
题目大意：
给定一个数组，其中是一些区间。将其中有交集的区间进行合并。

解题思路：
先排序，然后从前往后遍历就行。

遇到的问题：
竟然定义了一个vector之后，直接就ans[0]=...了。我也是醉了。
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
    class Cmp {
    public:
        bool operator() (const Interval &l, const Interval &r) const {
            return l.start < r.start;
        }
    };
    
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        if (intervals.size() < 2) return intervals;
        
        sort(intervals.begin(), intervals.end(), Cmp());
        
        vector<Interval> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (ans.back().end >= intervals[i].start) {
                ans.back().end = max(ans.back().end, intervals[i].end);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
    }
};