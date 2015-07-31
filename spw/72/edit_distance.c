/**
 * Problem: Given two words word1 and word2, find the minimum number 
 *          of steps required to convert word1 to word2. 
 *          (each operation is counted as 1 step.): delete, insert, replace
 * Solve: dynamic programme
 * Tips: delete, replace 
 */
#define min(a, b) ((a) < (b) ? (a) : (b))
int minDistance(char* word1, char* word2) {
	int len1 = strlen(word1);
	int len2 = strlen(word2);

	if (len1 == 0) return len2;
	else if (len2 == 0) return len1;

	int **dp = malloc(sizeof(int *) * (len1+1));
	int i, j;
	for (i = 0; i <= len1; ++i) {
		dp[i] = malloc(sizeof(int) * (len2+1));
	}

	for (i = 0; i <= len1; ++i) dp[i][0] = i;
	for (j = 0; j <= len2; ++j) dp[0][j] = j;

	for (i = 1; i <= len1; ++i) {
		for (j = 1; j <= len2; ++j) {
			if (word1[i-1] == word2[j-1]) {
				dp[i][j] = dp[i-1][j-1];
			} else {
				// minimum of the three: delete word1, delete word2, replace 
				dp[i][j] = min(dp[i][j-1], dp[i-1][j]);
				dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
				dp[i][j] += 1;
			}
		}
	}

	int ans = dp[len1][len2];
	for (i = 0; i <= len1; ++i) {
		free(dp[i]);
	} 
	free(dp);
	return ans;
}
