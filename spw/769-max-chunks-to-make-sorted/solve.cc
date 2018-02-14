/**
 * Problem: Given an array arr that is a permutation of
 *          [0, 1, ..., arr.length - 1], we split the array
 *          into some number of "chunks" (partitions), and
 *          individually sort each chunk.  After concatenating
 *          them, the result equals the sorted array.
 *
 *          What is the most number of chunks we could have made?
 *
 * Solve: count the chunks one by one
 * Tips: no
 */
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;

        int res = 0;

        int start = 0;
        int l = arr[0], r = arr[0];
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            l = min(arr[i], l);
            r = max(arr[i], r);
            cnt++;

            if (l == start && cnt == r-l+1) {
                res++;
                l = start = r+1;
                cnt = 0;
            }
        }

        return res;
    }
};
