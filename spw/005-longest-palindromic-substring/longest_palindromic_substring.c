#include <stdio.h>
#include <string.h>

#define N 1010
int dp[N][N];

/**
 * use the dp based on the sustring length enumeration
 */
char* longestPalindrome(char* s)
{
    memset(dp, 0, sizeof(dp));

    int len = strlen(s);
    int i, j, l;
    for (i = 0; i < len; ++i) {
        dp[i][i] = 1;
        dp[i+1][i] = 1;
    }

    int max_l = 1;
    int start = 0, end = 0;
    for (l = 0; l <= len-2; ++l) {
        for (i = 0, j = l+1; j < len; ++i, ++j) {
            if (s[i] == s[j] && dp[i+1][j-1]) {
                dp[i][j] = 1;
                max_l = max_l > l+2 ? max_l : l+2;
                start = i, end = j;
            }
        }
    }
    printf("Max len=%d\n", max_l);

    s[end+1] = '\0';
    return s+start;
}
int main()
{
    char str[1010];
    while(~scanf("%s", str)) {
        char *s = longestPalindrome(str);
        printf("the Longest Palindromic Substring is %s\n", s);
    }

    return 0;
}
string longestPalindrome(string s) {
    int start = 0, len = 0, n = s.size();

    string ans;
    for (int i = 0; i < n; ++i) {
        // cut branches
        if (len > (n - i) * 2) return ans;

        // skip all the substring have the same character.
        // because we have considered the Palindromic substring
        // used them as center
        int left = start, right = start;
        while (right+1 < n && s[right+1] == s[start]) ++right;
        start = right + 1;

        while (right+1 < n && left-1 >= 0 && s[left-1] == s[right+1]) {
            --left; ++right;
        }

        if (right - left + 1 > len) {
            len = right - left + 1;
            ans = s.substr(left, len);
        }
    }

    return ans;
}
