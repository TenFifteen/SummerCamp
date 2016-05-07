/**
 * Problem: Given an array of non-negative integers, you are initially
 *          positioned at the first index of the array.
 *          Each element in the array represents your maximum jump length at that position.
 *          Determine if you are able to reach the last index.
 * Solve: greedy & two pointers
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param A: A list of integers
         * @return: The boolean answer
         */
        bool canJump(vector<int> A) {
            int n = A.size();
            if (n <= 0) return 0;

            int start = 0, end = A[0];

            while (end < n-1) {
                int maxEnd = 0;

                for (int i = start+1; i <= end && maxEnd < n-1; ++i) {
                    maxEnd = max(maxEnd, i+A[i]);
                }

                if (maxEnd <= end) return false;
                start = end;
                end = maxEnd;
            }

            return true;
        }
};

