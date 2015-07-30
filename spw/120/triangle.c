#define min(a, b) ((a) < (b) ? (a) : (b))

/**
 * Problem: Given a triangle, find the minimum path sum from top to bottom.
 *          Each step you may move to adjacent numbers on the row below.
 * Solve: from bottom to top.
 * Tips: only O(n) space is allowed
 */
int minimumTotal(int **triangle, int numRows) {
	int *dp = malloc(sizeof(int) * (numRows+1));

	int i, j;
	for (i = 0; i < numRows; ++i) dp[i] = triangle[numRows-1][i];

	for (i = numRows-2; i >= 0; --i) {
		for (j = 0; j <= i; ++j) {
			dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
		}
	}

	int ans = dp[0];
	free(dp);
	return ans;
}
