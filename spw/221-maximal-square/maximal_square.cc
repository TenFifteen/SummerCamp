/**
 * Problem: Given a 2D binary matrix filled with 0's and 1's, find the
 *          largest square containing all 1's and return its area.
 * Solve: dp with the edge of largest square whose left bottom index is (i,j)
 *        then when matrix[i][j] = '1', edge[i][j] = min(edge[i][j-1], edge[i-1][j], edge[i-1][j-1])
 * Tips: 1. i/j from 1 then we have dp[i-1][j-1] valid for all i,j
 */
class Solution {
    public:
        int maximalSquare(vector<vector<char>>& matrix) {
            int m = matrix.size();
            if (!m) return 0;
            int n = matrix[0].size();

            int leftTop = 0;
            int edge = 0;
            vector<int> dp(n+1, 0);

            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    int tmp = dp[j];

                    if (matrix[i-1][j-1] == '0') {
                        dp[j] = 0;

                    } else {
                        dp[j] = min(min(dp[j-1], dp[j]), leftTop) + 1;
                        edge = max(edge, dp[j]);

                    }
                    leftTop = tmp;

                }

            }

            return edge*edge;

        }

};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() <= 0) return 0;

        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') dp[i+1][j+1] = 0;
                else {
                    dp[i+1][j+1] = min(dp[i][j], min(dp[i][j+1], dp[i+1][j])) + 1;
                    ans = max(ans, dp[i+1][j+1]);
                }
            }
        }

        return ans*ans;
    }
};
