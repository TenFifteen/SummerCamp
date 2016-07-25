/*
题目大意：
给一组排序的并且没有交集的区间，插入一个区间，如果有重复则合并。

解题思路：
本来想找到该区间的左边和右边，但是转念一想直接插进去按照刚才的方法不是直接可以做了么。

遇到的问题：
一次通过。
不过回头还是应该试试线性的算法。

再次阅读：
看到这个题目之后，感觉就是一遍遍历。不知道之前写的遇到的问题是什么意思了。
然后看了一下DISCUSS中的不错的代码，跟自己想的还是比较相投的：
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> ret;
    auto it = intervals.begin();
    for(; it!=intervals.end(); ++it){
        if(newInterval.end < (*it).start) //all intervals after will not overlap with the newInterval
            break;
        else if(newInterval.start > (*it).end) // *it will not overlap with the newInterval
            ret.push_back(*it);
        else{ //update newInterval bacause *it overlap with the newInterval
            newInterval.start = min(newInterval.start, (*it).start);
            newInterval.end = max(newInterval.end, (*it).end);
        }
    }
    // don't forget the rest of the intervals and the newInterval
    ret.push_back(newInterval);
    for(; it!=intervals.end(); ++it)
        ret.push_back(*it);
    return ret;
}
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
/*
第二次做：
这次比较顺利，只有两处手误。
而且写的时候就想到了，如果直接插入之后进行排序，再调用之前那道题的过程，也是可以做的。只不过可能
那样做起来还多了一个排序的复杂度。
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
    void pushback(vector<Interval> &intervals, Interval newInterval) {
        if (intervals.size() == 0 || intervals.rbegin()->end < newInterval.start) {
            intervals.push_back(newInterval);
        } else {
            intervals.rbegin()->end = max(intervals.rbegin()->end, newInterval.end);
        }
    }

public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        bool inserted = false;
        int index = 0;

        while (index < intervals.size()) {
            if (inserted || intervals[index].start < newInterval.start) {
                pushback(ans, intervals[index++]);
            } else {
                inserted = true;
                pushback(ans, newInterval);
            }
        }

        if (!inserted) pushback(ans, newInterval);
        return ans;
    }
};
/*
 * 可以
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
    void insertOne(vector<Interval> &ans, Interval &i) {
        if (ans.size() == 0 || ans.back().end < i.start) ans.push_back(i);
        else ans.back().end = max(ans.back().end, i.end);
    }

public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        bool inserted = false;
        for (int i = 0; i < intervals.size(); ++i) {
            if (inserted) {
                insertOne(ans, intervals[i]);
            } else {
                if (newInterval.start < intervals[i].start) {
                    insertOne(ans, newInterval);
                    inserted = true;
                }
                insertOne(ans, intervals[i]);
            }
        }

        if (inserted == false) insertOne(ans, newInterval);
        return ans;
    }
};
