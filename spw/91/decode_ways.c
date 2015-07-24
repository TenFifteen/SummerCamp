#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Problem: 'A--Z' --> '0 --> 26', then calculate the decode ways of the given sring 
 * Solve: dp
 * Tips: 1. zero, invalid
 *       2. calculte the first two first, then we needn't make judgement each time
 *          we make a reference of dp[i-2]
 */
int numDecodings(char* s) 
{
	if (s == NULL || s[0] == '0') return 0;
	
	int len = strlen(s);
	if (len <= 1) {
		return len;
	}

	int *dp = malloc(sizeof(int) * (len+1));

	// calculate the first two
	dp[0] = 1;
	dp[1] = 1;
	int s12 = (s[0] - '0') * 10 + (s[1] - '0');
	if (s12 > 20 && s12 % 10 == 0) {
		free(dp);
		return 0;
	}
	if (s12 != 10 && s12 != 20 && s12 < 27) dp[1] = 2;

	int i;
	for (i = 2; i < len; ++i) {
		switch(s[i-1]) {
			case '1':
				if (s[i] == '0') {
					dp[i] = dp[i-2];
				} else {
					dp[i] = dp[i-2] + dp[i-1];
				}
				break;
			case '2':
				if (s[i] == '0') {
					dp[i] = dp[i-2];
				} else if (s[i] > '6') {
					dp[i] = dp[i-1];
				} else {
					dp[i] = dp[i-2] + dp[i-1];
				}
				break;
			default:
				if (s[i] == '0') {
					free(dp);
					return 0;
				}
				dp[i] = dp[i-1];
		}
	}

	int ans = dp[len-1];
	free(dp);
	return ans;
}

int main()
{

	char nums[1000];
	while (~scanf("%s", nums)) {
		printf("The ways of decode %s is %d\n", nums, numDecodings(nums));
	}

	return 0;
}
