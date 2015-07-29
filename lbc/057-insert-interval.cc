/*
题目大意：
给一组排序的并且没有交集的区间，插入一个区间，如果有重复则合并。

解题思路：
本来想找到该区间的左边和右边，但是转念一想直接插进去按照刚才的方法不是直接可以做了么。

遇到的问题：
一次通过。
不过回头还是应该试试线性的算法。
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    class Cmp{
        public:
        bool operator() (const Interval &left, const Interval &right){
            if(left.start < right.start)return true;
            else if(left.start == right.start)return left.end < right.end;
            else return false;
        }
    };
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), Cmp());
        if(intervals.size() == 0)return ans;
        Interval cur = intervals[0];
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i].start <= cur.end){
                cur.end = max(cur.end, intervals[i].end);
            }else{
                ans.push_back(cur);
                cur = intervals[i];
            }
        }
        ans.push_back(cur);
        
        return ans;
    }
};