/*
题目大意：
给一组区间，要求合并有交集的区间。

解题思路：
先按照start排序，然后从前往后合并。

遇到的问题：
一次通过。
就是那个排序的自定义排序不是很熟。

再次阅读：
这次想到的算法还是现在这个算法，看了之前的代码，感觉也是可以的。
去DISCUSS中看了一下别人的代码，感觉基本也就是这样了。
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
/*
第二次做：
比较顺利，就是比较函数又忘记了加括号了。
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
private:
    struct Cmp {
        bool operator() (const Interval &lh, const Interval &rh) const {
            return lh.start < rh.start;
        }
    };
    
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0) return intervals;
        
        sort(intervals.begin(), intervals.end(), Cmp());
        
        vector<Interval> ans;
        ans.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start <= ans.rbegin()->end) {
                ans.rbegin()->end = max(ans.rbegin()->end, intervals[i].end);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
    }
};