/**
 * Problem: Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *          Each element in the array represents your maximum jump length at that position.
 *          Your goal is to reach the last index in the minimum number of jumps.
 * Solve: use two pointers & greedy
 * Tips: the initialization of step must be 1 instead of 0, because of we use end to judge.
 */
class Solution {
    public:
        /**
         * @param A: A list of lists of integers
         * @return: An integer
         */
        int jump(vector<int> A) {
            int n = A.size();

            if (n == 0) return 0;

            int start = 0, end = A[0];
            int step = 1;

            while (end < n-1) {

                int maxEnd = 0;
                for (int i = start+1; i <= end && maxEnd < n-1; ++i) {
                    if (maxEnd < A[i]+i) {
                        maxEnd = A[i] + i;
                    }
                }

                start = end;
                end = maxEnd;
                ++step;
            }

            return step;
        }
};
