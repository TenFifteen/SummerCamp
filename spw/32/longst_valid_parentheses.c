#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100
int dp[N];//dp[i] means the lenght of longset valid parentheses string that ends with s[i]

/**
 * Problem: find the length of the longest valid (well-formed) parentheses substring.
 * Solve: use dynamic programming to solve this question where dp[i] means the longest valid 
 *        string end with s[i]. The idea was copied from the discuss board.
 *        I use dp[i][j] at first which means the longest valid string of s[i...j], obviously, 
 *        I find a wrong pointcut.
 * Tips: see the comments in the code
 */
int longestValidParentheses(char* s) 
{
	if (s == NULL) return 0;

	int len = strlen(s);
	if (len == 0 || len == 1) return 0;

	dp[0] = 0;
	if (s[0] == '(' && s[1] == ')') {
		dp[1] = 2;
	} else {
		dp[1] = 0;
	}

	int max_len = dp[1];
	int i;
	for (i = 2; i < len; ++i) {
		if (s[i] == '(') {
			dp[i] = 0;
		} else {
			if (s[i-1] == '(') {
				dp[i] = dp[i-2] + 2;
			} else {
				int pos = i - 1 - dp[i-1];
				if (pos < 0 || s[pos] == ')') {
					dp[i] = 0;
				} else {
					dp[i] = dp[i-1] + 2;
					// we should add the dp[pos-1] if it is not zero
					if (--pos > 0 && dp[pos] > 0) {
						dp[i] += dp[pos];
					}
				}
			} 
		}

		if (max_len < dp[i]) max_len = dp[i];
	}

	return max_len;
}

int main()
{
	char str[N];
	while (~scanf("%s", str)) {
		printf("The longset valid parentheses of string %s is %d\n", 
				str, longestValidParentheses(str));
	}

	return 0;
}
