/*
题目大意：
给一组区间，要求合并有交集的区间。

解题思路：
先按照start排序，然后从前往后合并。

遇到的问题：
一次通过。
就是那个排序的自定义排序不是很熟。
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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
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