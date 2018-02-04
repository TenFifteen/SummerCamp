/**
 * Problem: We are given a list schedule of employees, which represents
 *          the working time for each employee.
 *          Each employee has a list of non-overlapping Intervals, and these
 *          intervals are in sorted order.
 *          Return the list of finite intervals representing common,
 *          positive-length free time for all employees, also in sorted order.
 * Solve: heap + mrege
 * Tips: no
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
typedef vector<Interval>::iterator Itor;
typedef pair<Itor, Itor> Ele;

class Cmp{
	public:
		bool operator()(const Ele& pairA, const Ele& pairB) const {
			const Itor a = pairA.first, b = pairB.first;

			if (a->start != b->start) return a->start > b->start;
			else return a->end > b->end;
		}
};

class Solution {
	void mergeInterval(vector<Interval>& intervals, Interval& now) {
		if (intervals.empty()) {
			intervals.push_back(now);
			return;
		}

		Interval& prev = intervals.back();
		if (now.start > prev.end) {
			intervals.push_back(now);
		} else if (now.end > prev.end){
			prev.end = now.end;
		}
	}
	public:
	vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
		priority_queue<Ele, vector<Ele>, Cmp> heap;

		for (auto& intervals : schedule) {
			if (!intervals.empty()) {
				heap.push(make_pair(intervals.begin(), intervals.end()));
			}
		}

		vector<Interval> mergedIntervals;
		while (!heap.empty()) {
			Ele now = heap.top();
			heap.pop();

			mergeInterval(mergedIntervals, *(now.first));

			now.first++;
			if (now.first != now.second) heap.push(now);
		}

		vector<Interval> res;
		if (mergedIntervals.size() < 2) return res;

		Interval prev = mergedIntervals[0];
		for (int i = 1; i < mergedIntervals.size(); ++i) {
			Interval& now = mergedIntervals[i];

			res.push_back(Interval(prev.end, now.start));
			prev = now;
		}

		return res;
	}
};
