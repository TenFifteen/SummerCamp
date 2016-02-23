#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Definition of Interval:
 */
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

/**
 * Problem: Given a collection of intervals, merge all overlapping intervals.
 * Solve: sort and traversal.
 * Tips: 1. The compare method passed to the sort method must be static, the
 *          parameters must be constant and passed by reference.
 *       2. Use two variables, begin and end, iterator and update them. Then push
 *          to the answer set when it necessary.
 *       3. We can also use the 'ans' as a stack, when iterator, just push the element
 *          then compare now interval's begin and the stack top interval's end
 *          and then determine if construct a new Interval. Then push back.
 */
class Solution {
public:
    static bool cmp(const Interval &a, const Interval &b) {
        return a.start < b.start;
    }
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        vector<Interval> ans;
        int s = intervals[0].start, e = intervals[0].end;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start > e) {
                Interval tmp(s, e);
                ans.push_back(tmp);
                s = intervals[i].start;
                e = intervals[i].end;
            } else if (intervals[i].end > e){
                e = intervals[i].end;
            }
        }

        Interval tmp(s, e);
        ans.push_back(tmp);
        return ans;
    }
};
int main()
{

}
