#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100

/**
 * Problem: Given a string S and a string T, count the number of distinct subsequences of T in S.
 * Solve: dp[i][j] means the solution of s[1...j] and t[1...i]
 * Tips: initialize
 */
int numDistinct(char* s, char* t)  
{
	if (s == NULL || t == NULL) return 0;
	int len_s = strlen(s);
	int len_t = strlen(t);
	if (len_t == 0 || len_s == 0) return 0;

	int i, j;
	int **dp = malloc(sizeof(int *) * (len_t + 1));
	for (i = 0; i < len_t+1; ++i) {
		dp[i] = malloc(sizeof(int) * (len_s + 1));
	}

	dp[1][0] = 0;
	for (j = 1; j <= len_s; ++j) {
		if (s[j-1] == t[0]) {
			dp[1][j] = dp[1][j-1] + 1;
		} else {
			dp[1][j] = dp[1][j-1];
		}
	}   

	for (i = 2; i <= len_t; ++i) {
		for (j = 1; j <= len_s; ++j) {
			if (j < i) {
				dp[i][j] = 0;
				continue;
			}   

			if (s[j-1] == t[i-1]) {
				dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
			} else {
				dp[i][j] = dp[i][j-1];
			}   
		}   
	}   

	return dp[len_t][len_s];
}

/**
 * copy from the discuss board
 * this solution iterate in every column of the solution above
 */
int numDistinct1(char* s, char* t)  
{
	int len_s = strlen(s);
	int len_t = strlen(t);

	int i, j;
	int *dp = malloc(sizeof(int ) * (len_t + 1));

	dp[0] = 1;
	for (i = 1; i <= len_s; ++i) {
		for (j = len_t; j >= 1; --j) {
			if (s[i-1] == t[j-1]) {
				dp[j] += dp[j-1];
			}  
		}   
	}   

	return dp[len_t];
}
int main()
{
	char s[N], t[N];
	while (~scanf("%s %s", s, t)) {
		printf("The count of string %s 's subsequences which is %s is %d\n", s, t, numDistinct1(s, t));
	}

	return 0;
}
