/**
 * Problem: Given a 2D binary matrix filled with 0's and 1's, find
 *          the largest square containing all 1's and return its area.
 * Solve: dp[j] = min(min(dp[j], dp[j-1]), last_left) + 1;
 * Tips: see comments below
 */
class Solution {
    public:
        /**
         * @param matrix: a matrix of 0 and 1
         * @return: an integer
         */
        int maxSquare(vector<vector<int> > &matrix) {
            // write your code here
            int m = matrix.size();
            if (m == 0) return 0;
            int n = matrix[0].size();

            vector<int> dp(n+1, 0);

            int ans = 0;
            int last_left = 0;
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    int tmp = dp[j];
                    if (matrix[i-1][j-1] == 1) {
                        dp[j] = min(min(dp[j], dp[j-1]), last_left) + 1;
                        ans = max(dp[j], ans);
                    } else {
                        //in 2d dp, this sentence can be ignored
                        dp[j] = 0;
                    }
                    last_left = tmp;
                }
            }

            return ans*ans;
        }
};
