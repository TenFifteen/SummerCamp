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


class Solution {
    public:
        int numDecodings(string s) {
            int n = s.size();
            if (n == 0) return 0;

            vector<int> dp(n+1, 0);
            dp[0] = 1;

            if (s[0] == '0') return 0;
            else dp[1] = 1;

            for (int i = 2; i <= n && dp[i-1]; ++i) {
                if (s[i-1] == '0' && s[i-2] != '1' && s[i-2] != '2')
                    return 0;

                int num = (s[i-2] - '0') * 10 + (s[i-1] - '0');
                if (num < 9 || num > 26) dp[i] = dp[i-1];
                else if (num == 10 || num == 20) dp[i] = dp[i-2];
                else dp[i] = dp[i-1] + dp[i-2];

            }

            return dp[n];
        }
}


/**
 * Solve: 1. consider s[i] == '0' first
 *       2.
 */
int numDecodings(string s) {
    if (!s.size() || s.front() == '0') return 0;
    // r2: decode ways of s[i-2] , r1: decode ways of s[i-1]•
    int r1 = 1, r2 = 1;

    for (int i = 1; i < s.size(); i++) {
        // zero voids ways of the last because zero cannot be used separately
        if (s[i] == '0') r1 = 0;

        // possible two-digit letter, so new r1 is sum of both while new r2 is the old r1
        if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
            r1 = r2 + r1;
            r2 = r1 - r2;
        }

        // one-digit letter, no new way added
        else {
            r2 = r1;
        }
    }

    return r1;
}

