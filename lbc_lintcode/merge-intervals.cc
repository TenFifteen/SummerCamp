/*
题目：19 % 合并区间 容易

题目大意：
给定一组区间，将其中有交叉的区间进行合并。

解题思路：
将区间排序之后，依次检查就行了。

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
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    struct Cmp {
        bool operator() (const Interval &lh, const Interval &rh) {
            if (lh.start < rh.start) return true;
            if (lh.start > rh.start) return false;
            return lh.end < rh.end;
        }
    };
    
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        sort(intervals.begin(), intervals.end(), Cmp());
        vector<Interval> ans;
        if (intervals.size() == 0) return ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start > ans[ans.size()-1].end) {
                ans.push_back(intervals[i]);
            } else {
                ans[ans.size()-1].end = max(ans[ans.size()-1].end, intervals[i].end);
            }
        }
        return ans;
    }
};
