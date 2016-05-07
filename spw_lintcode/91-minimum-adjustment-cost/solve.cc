/**
 * Problem: Given an integer array, adjust each integers so that the difference
 *          of every adjacent integers are not greater than a given number target.
 *          If the array before adjustment is A, the array after adjustment is B,
 *          you should minimize the sum of |A[i]-B[i]|
 * Solve: backpack. Enumeration on all possible value(which between 1 and 100).
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param A: An integer array.
         * @param target: An integer.
         */
        int MinAdjustmentCost(vector<int> A, int target) {
            int n = A.size();

            // dp[i][j] (the minimum diff value sum when A[i] is set to j)
            vector<vector<int> > dp(n, vector<int>(101, INT_MAX));

            for (int i = 0; i < n; ++i) {
                for (int j = 1; j <= 100; ++j) {
                    if (i == 0) dp[i][j] = abs(A[i] - j);
                    else {
                        int left = max(j-target, 1);
                        int right = min(j+target, 100);
                        for (int k = left; k <= right; ++k) {
                            dp[i][j] = min(dp[i][j], dp[i-1][k] + abs(A[i]-j));
                        }
                    }
                }
            }

            int ans = INT_MAX;
            for (int i = 1; i <= 100; ++i) {
                ans = min(ans, dp[n-1][i]);
            }

            return ans;
        }
};
