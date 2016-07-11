#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isMatch(char *s, char *p) 
{
	int len1 = strlen(s);
	int len2 = strlen(p);

	int i, j;
	int **dp = malloc(sizeof(int *) * (len1));
	for (i = 0; i < len1; ++i) {
		dp[i] = malloc(sizeof(int) * len2);
		for (j = 0; j < len2; ++j) dp[i][j] = -1;
	}
	int result = getMatch(s, p, 0, 0, dp);
	
	for (i = 0; i < len1; ++i) {
		free(dp[i]);
	}
	free(dp);
	return result;
}

int getMatch(char *s, char *p, int m, int n, int **dp) 
{
	int len1 = strlen(s);
	int len2 = strlen(p);

	if (m >= len1 || n >= len2) {
		return m >= len1 && n >= len2;
	}
	if (dp[m][n] != -1) return dp[m][n];

	int i = m, j = n;
	while(j < len2) {
		if (p[j] == '*') {
			if (getMatch(s, p, i, j+1, dp) == 1) {
				return dp[m][n] = 1;
			}
		} 		

		if (i >= len1 || p[j] != '*' && p[j] != '?' && p[j] != s[i]) return dp[m][n] = 0; 
		if (p[j] != '*') ++j;
		++i;
	}

	return dp[m][n] = (i >= len1 ? 1 : 0);
}

int main()
{
	char s[1000], p[1000];
	while (~scanf("%s %s", s, p)) {
		printf("%d\n", isMatch(s, p));
	}

	return 0;
}
