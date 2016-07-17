#include <stdio.h>
#include <stdlib.h>

/**
 * Problem: find minimum path
 * Solve: simple dp
 */
#define min(a, b) ((a) < (b) ? (a) : (b))
int minPathSum(int** grid, int gridRowSize, int gridColSize)
{
	if (gridColSize == 0 || gridRowSize == 0) return 0;

	int **dp = malloc(sizeof(int *) * (gridRowSize));
	int i, j;
	for (i = 0; i < gridRowSize; ++i) {
		dp[i] = malloc(sizeof(int) * (gridColSize));
	}

	dp[0][0] = grid[0][0];
	for (i = 1; i < gridRowSize; ++i) dp[i][0] = dp[i-1][0] +  grid[i][0];
	for (j = 1; j < gridColSize; ++j) dp[0][j] = dp[0][j-1] + grid[0][j];

	for (i = 1; i < gridRowSize; ++i) {
		for (j = 1; j < gridColSize; ++j) {
			dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
		}
	}

	return dp[gridRowSize-1][gridColSize-1];
}
int main()
{

}

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m < 1) return 0;
        int n = grid[0].size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        dp[0][1] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = grid[i-1][j-1] + min(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[m][n];
    }
};
