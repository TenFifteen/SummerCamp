/**
 * Problem: Given n items with size Ai and value Vi, and a backpack
 *          with size m. What's the maximum value can you put into the backpack?
 * Solve:  just backpack
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param m: An integer m denotes the size of a backpack
         * @param A & V: Given n items with size A[i] and value V[i]
         * @return: The maximum value
         */
        int backPackII(int m, vector<int> A, vector<int> V) {
            int n = A.size();
            vector<int> dp(m+1, 0);

            for (int i = 0; i < n; ++i) {
                for (int j = m; j >= A[i]; --j) {
                    dp[j] = max(dp[j], dp[j-A[i]]+V[i]);
                }
            }

            return dp[m];
        }
};
