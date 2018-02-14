/**
 * Problem: An integer interval [a, b] (for integers a < b) is a set of all
 *          consecutive integers from a to b, including a and b.
 *
 *          Find the minimum size of a set S such that for every integer
 *          interval A in intervals, the intersection of S with A has size at least 2.
 * Solve: 1. sort start point ascending, and end point descending.
 *        2. calculate from the end
 * Tips: greedy alogrithm always think from the last one
 */
class Solution {
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    }
    public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int n = intervals.size();
        vector<int> tofill(n, 2);

        int res = 0;
        while (--n >= 0) {
            int s = intervals[n][0];
            int e = intervals[n][1];

            int p = tofill[n];
            for (int i = s; i < s + p; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (tofill[j] > 0 && intervals[j][1] >= i)
                        --tofill[j];
                }
                ++res;
            }
        }

        return res;
    }
};
