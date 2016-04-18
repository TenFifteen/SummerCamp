/**
 * Problem: Given a triangle, find the minimum path sum from top to bottom.
 *          Each step you may move to adjacent numbers on the row below.
 * Solve: dp
 * Tips: use 2d matrix.
 */
class Solution {
    public:
        /**
         * @param triangle: a list of lists of integers.
         * @return: An integer, minimum path sum.
         */
        int minimumTotal(vector<vector<int> > &triangle) {
            int m = triangle.size();
            if (m == 0) return 0;

            vector<vector<int>> dp(m+1, vector<int>(m+1, 0));
            for (int i = m-1; i >= 0; --i) {
                for (int j = 0; j <= i; ++j) {
                    dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
                }
            }

            return dp[0][0];
        }
};
