/**
 * Problem: Given a non-overlapping interval list which is sorted by start point.
 *          Insert a new interval into it, make sure the list is still in order
 *          and non-overlapping (merge intervals if necessary).
 * Solve: a new vector.
 * Tips: see comments below
 */
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
class Solution {
    public:
        /**
         * Insert newInterval into intervals.
         * @param intervals: Sorted interval list.
         * @param newInterval: new interval.
         * @return: A new interval list.
         */
        vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
            int n = intervals.size();

            bool inserted = false;
            vector<Interval> ans;
            int i = 0;
            while (i < n && !inserted) {
                if (newInterval.end < intervals[i].start) {
                    ans.push_back(newInterval);
                    // push the interval[i] or it will be skipped
                    ans.push_back(intervals[i]);
                    inserted = true;
                } else if (intervals[i].end < newInterval.start) {
                    ans.push_back(intervals[i]);
                } else {
                    newInterval.start = min(newInterval.start, intervals[i].start);
                    newInterval.end = max(newInterval.end, intervals[i].end);
                }

                ++i;
            }

            while (i < n) {
                ans.push_back(intervals[i]);
                ++i;
            }

            if (!inserted) ans.push_back(newInterval);

            return ans;
        }
};
