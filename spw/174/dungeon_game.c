#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
/**
 * Problem: 
 */
int calculateMinimumHP(int dungeon[][100], int row, int col) 
{
	int **dp = malloc(sizeof(int *) * row);
	int i, j;
	for (i = 0; i < row; ++i) {
		dp[i] = malloc(sizeof(int) * col);
	}

	dp[0][0] = dungeon[0][0];
	for (i = 1; i < row; ++i) dp[i][0] = dp[i-1][0] + dungeon[i][0];
	for (i = 1; i < col; ++i) dp[0][i] = dp[0][i-1] + dungeon[0][i];

	for (i = 1; i < row; ++i) {
		for (j = 1; j < col; ++j) {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + dungeon[i][j];
		}
	}

	int ans = dp[row-1][col-1];
	for (i = 0; i < row; ++i) {
		free(dp[i]);
	}
	free(dp);
	return ans > 0 ? 0 : -ans;
}

int main()
{
	int arr[100][100];
	int m, n;
	while (~scanf("%d %d", &m, &n)) {
		int i, j;
		for (i = 0; i < m; i++)	{
			for (j = 0; j < n; j++)	{
				scanf("%d", &arr[i][j]);
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		printf("The initial health is %d\n", calculateMinimumHP(arr, m, n));
	}

	return 0;
}
