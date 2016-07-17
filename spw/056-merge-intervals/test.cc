#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

static bool cmp(const Interval &a, const Interval &b) {
    return a.start < b.start;

}
vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> ans;
    int n = intervals.size();
    if (n == 0) return ans;

    sort(intervals.begin(), intervals.end(), cmp);
    ans.push_back(intervals[0]);

    for (int i = 1; i < n; ++i) {
        if (intervals[i].start > ans.back().end) {
            ans.push_back(intervals[i]);

        } else {
            ans.back().end = max(intervals[i].end, ans.back().end);

        }

    }

    return ans;

}


int main()
{
    Interval tmp1(1, 3);
    Interval tmp2(2, 4);
    vector<Interval> in;
    in.push_back(tmp1);
    in.push_back(tmp2);

    vector<Interval> ans = merge(in);
    for (Interval a : ans) {
        cout << a.start << "," << a.end << endl;
    }

    return 0;
}
