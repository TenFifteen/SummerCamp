#include <cstdio>
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

/**
 * Problem: Given a collection of intervals, merge all overlapping intervals.
 * Solve: sort and merge one by one
 * Tips: see comment below
 */
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
	vector<Interval> ans;
	if (intervals.size() == 0) {
		ans.push_back(newInterval);
		return ans;
	}

	// find the first value that above newInterval->start, because the function
	// 'insert' insert element before 'it'
	for (it = intervals.begin(); it != intervals.end() && it->start < newInterval.start; ++it) ;
	intervals.insert(it, newInterval);

	ans.push_back(intervals[0]);
	for (int i = 1; i < intervals.size(); ++i) {
		if (intervals[i].start <= ans.back().end) {
			Interval temp(ans.back().start, max(intervals[i].end, ans.back().end));
			ans.pop_back();
			ans.push_back(temp);
		} else {
			ans.push_back(intervals[i]);
		}
	}
	return ans;
}

int main()
{

}

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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;

        int i = 0, n = intervals.size();
        while (i < n || newInterval.start <= newInterval.end ) {
            if (newInterval.start > newInterval.end || i < n && intervals[i].start < newInterval.start) {
                if (ans.empty() || intervals[i].start > ans.back().end) {
                    ans.push_back(intervals[i++]);
                } else {
                    ans.back().end = max(ans.back().end, intervals[i++].end);
                }
            } else {
                if (ans.empty() || newInterval.start > ans.back().end) {
                    ans.push_back(newInterval);
                } else {
                    ans.back().end = max(ans.back().end, newInterval.end);
                }
                // in case start == end;
                swap(newInterval.start, newInterval.end);
                newInterval.start++;
            }
        }

        return ans;
    }
};
