/**
 * Problem: the count of path from top-left corner to the bottom-right corner
 * Solve: simple dp
 */
int uniquePaths(int m, int n) {
	int dp[100][100];

	int i, j;
	for (i = 0; i < m; ++i) {
		dp[i][0] = 1;
	}
	for (j = 0; j < n; ++j) {
		dp[0][j] = 1;   
	}
	for (i = 1; i < m; ++i) {
		for (j = 1; j < n; ++j) {
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}
	return dp[m-1][n-1];
}
