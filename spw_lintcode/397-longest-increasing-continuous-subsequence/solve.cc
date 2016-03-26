/**
 * Problem: Give an integer array，find the longest increasing or
 *          decreasing continuous subsequence in this array.
 * Solve: use two variable: up and down.
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param A an array of Integer
         * @return  an integer
         */
        int longestIncreasingContinuousSubsequence(vector<int>& A) {
            // Write your code here
            int n = A.size();
            if (n <= 1) return n;


            int up = 1, down = 1;
            int ans = 1;

            for (int i = 1; i < n; ++i) {
                if (A[i] > A[i-1]) {
                    up++;
                    down = 1;
                } else if (A[i] < A[i-1]) {
                    down++;
                    up = 1;
                } else {
                    up = down = 1;
                }

                ans = max(ans, up);
                ans = max(ans, down);
            }

            return ans;
        }
};
