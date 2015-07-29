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