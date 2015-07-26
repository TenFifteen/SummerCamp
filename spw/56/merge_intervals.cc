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

bool comp(const Interval &a, const Interval &b)
{
	return a.start < b.start;
}
/**
 * Problem: Given a collection of intervals, merge all overlapping intervals.
 * Solve: sort and merge one by one
 * Tips: the comp should be static
 */
vector<Interval> merge(vector<Interval>& intervals) 
{
	vector<Interval> ans;
	if (intervals.size() == 0) return ans;

	sort(intervals.begin(), intervals.end(), comp);

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
